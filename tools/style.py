#!/usr/bin/env python3
"""Format or check maintained C/C++ under src/ and include/.

Run from the repository root with uv run --locked python tools/style.py.
Only the format command writes source files. No command builds game artifacts.
"""

import argparse
import os
from pathlib import Path
import subprocess
import sys
import sysconfig

PROJECT_ROOT = Path(__file__).resolve().parent.parent
SOURCE_ROOTS = (PROJECT_ROOT / "src", PROJECT_ROOT / "include")
EXTENSIONS = {".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp", ".hxx"}
BATCH_SIZE = 100


def validate_path(path: Path) -> Path:
    """Reject explicit paths outside maintained source, including symlink escapes."""
    resolved = path.resolve()
    if not any(resolved.is_relative_to(root) for root in SOURCE_ROOTS):
        raise ValueError(f"Path must be under src/ or include/: {path}")
    if path.is_symlink():
        raise ValueError(f"Symlink inputs are not supported: {path}")
    if not resolved.exists():
        raise ValueError(f"Path does not exist: {path}")
    return resolved


def collect_files(paths: list[Path]) -> list[Path]:
    """Expand directories deterministically, without following source symlinks."""
    files = set()
    for selected in paths:
        selected = validate_path(selected)
        if selected.is_file():
            if selected.suffix not in EXTENSIONS:
                raise ValueError(f"Unsupported source extension: {selected}")
            files.add(selected)
            continue

        for directory, subdirectories, filenames in os.walk(selected):
            directory_path = Path(directory)
            subdirectories[:] = sorted(
                name
                for name in subdirectories
                if not (directory_path / name).is_symlink()
            )
            for filename in filenames:
                candidate = directory_path / filename
                if candidate.is_symlink() or candidate.suffix not in EXTENSIONS:
                    continue
                if candidate.is_file():
                    files.add(validate_path(candidate))
    return sorted(files)


def find_tool(name: str) -> Path:
    """Use the running Python environment, never an unrelated PATH installation."""
    executable_name = f"{name}.exe" if os.name == "nt" else name
    executable = Path(sysconfig.get_path("scripts")) / executable_name
    if not executable.is_file():
        raise ValueError(
            f"Missing {name} in this Python environment. "
            "Run uv sync --locked, then use uv run --locked python tools/style.py."
        )
    return executable


def run_batches(command: list[str], files: list[Path]) -> bool:
    """Keep command lines bounded and report every selected file's diagnostics."""
    succeeded = True
    for offset in range(0, len(files), BATCH_SIZE):
        batch = files[offset : offset + BATCH_SIZE]
        result = subprocess.run(
            [*command, *(str(path) for path in batch)],
            cwd=PROJECT_ROOT,
            check=False,
        )
        if result.returncode != 0:
            succeeded = False
    return succeeded


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "command",
        choices=("check", "format", "lint"),
        nargs="?",
        default="check",
        help="check formatting and lint (default), format in place, or lint only",
    )
    parser.add_argument(
        "paths",
        nargs="*",
        type=Path,
        help="files/directories relative to the current directory; default: src/ include/",
    )
    args = parser.parse_args()

    try:
        files = collect_files(args.paths or list(SOURCE_ROOTS))
        if not files:
            print("No supported C/C++ files found in the selected source paths.")
            return 0

        # Resolve all required tools before beginning a potentially writing command.
        formatter = find_tool("clang-format") if args.command != "lint" else None
        linter = find_tool("cpplint") if args.command != "format" else None
        succeeded = True
        if formatter is not None:
            options = ["-i"] if args.command == "format" else ["--dry-run", "--Werror"]
            print(f"{args.command}: formatting {len(files)} file(s)", flush=True)
            succeeded = run_batches(
                [
                    str(formatter),
                    f"--style=file:{PROJECT_ROOT / '.clang-format'}",
                    *options,
                ],
                files,
            )

        if linter is not None:
            print(f"lint: checking {len(files)} file(s)", flush=True)
            extensions = ",".join(sorted(extension[1:] for extension in EXTENSIONS))
            lint_passed = run_batches(
                [str(linter), f"--extensions={extensions}"], files
            )
            succeeded = succeeded and lint_passed
        return 0 if succeeded else 1
    except (ValueError, OSError) as error:
        print(f"style: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())

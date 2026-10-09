# Matching goal checkpoint

## State

- Goal active; default region is `GUPE8P`. Start-of-turn Git state was clean at
  `work` / `e81fa44` (`origin/main`).
- Baseline identity: `orig/{GUPE8P,GUPJ8P,GUPP8P}/sys/main.dol` each matches its
  configured SHA-1. Active generated config is USA.
- Source progress is zero: `src/` and `include/` contain no maintained files; the
  two configured Runtime candidates are `NonMatching`. Current USA report has
  1,091 units (1,090 auto-generated), 4,854,724 code bytes, 1,396,732 data bytes,
  and 34,026 functions. Its 100% auto-unit scores do not represent source matches;
  no source-linked code or data is counted.

## Current focus: GUPE8P baseline linker launch

- `uv run --locked python configure.py` passed. `uv run --locked ninja` failed at
  `LINK build/GUPE8P/main.elf`: pinned `build/tools/wibo` 1.0.3 exits 139 while
  starting `build/compilers/GC/2.7/mwldeppc.exe`.
- `wibo --version` works, but running either the linker or unrelated
  `sjiswrap.exe` with `-h` also segfaults (139). `WIBO_DEBUG=1` reaches LDT setup;
  `strace` records SIGSEGV at null immediately after `modify_ldt`. This is a host
  PE-wrapper startup failure, before linker inputs are read. No Wine executable is
  available. Keep pinned compiler/linker and hashes unchanged.
- `build/GUPE8P/report.json` was refreshed, but `main.elf` and `main.dol` are from
  22:01, before this failed link. Their existing SHA-1 and byte comparison pass,
  but they are stale and do not verify the current build.
- Tool paths/versions: `.venv` Python 3.14.7, Ninja 1.13.2; `build/tools/dtk`
  1.8.3; `build/tools/objdiff-cli` 3.6.1; compiler/linker package `GC/2.7`.

## Next action

Resolve PE32 execution for the existing pinned toolchain (or use a controlled,
documented host wrapper override), then rerun the fresh USA baseline and verify the
new linked DOL. Only after a passing baseline, select one bounded source unit.
Other regions have verified original identities but have not been built.

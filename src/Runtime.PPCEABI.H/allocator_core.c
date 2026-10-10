#if defined(VERSION_GUPJ8P)
#define ALLOCATOR_RESIZE_FUNCTION fn_803A34CC
#define ALLOCATOR_ALLOCATE_HELPER fn_803A3CD8
#define ALLOCATOR_RELEASE_HELPER fn_803A3C80
#elif defined(VERSION_GUPP8P)
#define ALLOCATOR_RESIZE_FUNCTION fn_803A3EDC
#define ALLOCATOR_ALLOCATE_HELPER fn_803A46E8
#define ALLOCATOR_RELEASE_HELPER fn_803A4690
#else
#define ALLOCATOR_RESIZE_FUNCTION fn_803A2E8C
#define ALLOCATOR_ALLOCATE_HELPER fn_803A3698
#define ALLOCATOR_RELEASE_HELPER fn_803A3640
#endif

#define BLOCK_SIZE_MASK 0xFFFFFFF8
#define BLOCK_FLAG_2 0x2
#define BLOCK_FLAG_4 0x4
#define MINIMUM_BLOCK_SIZE 0x50

typedef struct AllocatorBlock AllocatorBlock;
typedef struct AllocatorArea AllocatorArea;

struct AllocatorBlock {
    unsigned int size_flags;
    unsigned int tagged_area;
    AllocatorBlock *previous_free;
    AllocatorBlock *next_free;
};

struct AllocatorArea {
    AllocatorArea *previous_area;
    AllocatorArea *next_area;
    unsigned int largest_free_size;
    unsigned int free_list_offset;
    unsigned int active_block_count;
};

extern void *ALLOCATOR_ALLOCATE_HELPER(void *heap, unsigned int size);
extern void ALLOCATOR_RELEASE_HELPER(void *heap, void *ptr);
extern void *memcpy(void *destination, const void *source, unsigned int size);

static inline unsigned int BlockSize(AllocatorBlock *block) {
    return block->size_flags & BLOCK_SIZE_MASK;
}

static inline AllocatorArea *BlockArea(AllocatorBlock *block) {
    return (AllocatorArea *)(block->tagged_area & ~1);
}

#define FREE_LIST_SLOT(area_arg, offset_arg)                                                       \
    (*(AllocatorBlock **)((unsigned char *)(area_arg) + (offset_arg)))

static inline unsigned int FreeListOffset(AllocatorArea *area) {
    return (area->free_list_offset & BLOCK_SIZE_MASK) - 4;
}

static inline void UnlinkFreeBlock(AllocatorArea *area, unsigned int offset,
                                   AllocatorBlock *block) {
    if (FREE_LIST_SLOT(area, offset) == block) {
        FREE_LIST_SLOT(area, offset) = block->next_free;
        if (FREE_LIST_SLOT(area, offset) == block) {
            FREE_LIST_SLOT(area, offset) = 0;
        }
    }

    block->next_free->previous_free = block->previous_free;
    block->previous_free->next_free = block->next_free;
}

/* Keep the target's repeated boundary-tag updates in the allocator-core function body. */
#define INSERT_FREE_BLOCK(area_arg, block_arg)                                                     \
    do {                                                                                           \
        AllocatorArea *insert_area = (area_arg);                                                   \
        AllocatorBlock *insert_block = (block_arg);                                                \
        unsigned int insert_head_offset;                                                           \
        AllocatorBlock *insert_following;                                                          \
        AllocatorBlock *insert_previous;                                                           \
        unsigned int insert_size;                                                                  \
        unsigned int insert_previous_size;                                                         \
        unsigned int insert_following_size;                                                        \
        unsigned int insert_flags;                                                                 \
        insert_head_offset = FreeListOffset(insert_area);                                          \
        if (FREE_LIST_SLOT(insert_area, insert_head_offset) == 0) {                                \
            FREE_LIST_SLOT(insert_area, insert_head_offset) = insert_block;                        \
            insert_block->previous_free = insert_block;                                            \
            insert_block->next_free = insert_block;                                                \
        } else {                                                                                   \
            insert_block->previous_free =                                                          \
                FREE_LIST_SLOT(insert_area, insert_head_offset)->previous_free;                    \
            insert_block->previous_free->next_free = insert_block;                                 \
            insert_block->next_free = FREE_LIST_SLOT(insert_area, insert_head_offset);             \
            insert_block->next_free->previous_free = insert_block;                                 \
            FREE_LIST_SLOT(insert_area, insert_head_offset) = insert_block;                        \
        }                                                                                          \
        if ((insert_block->size_flags & BLOCK_FLAG_4) == 0) {                                      \
            insert_previous_size = *(unsigned int *)((unsigned char *)insert_block - 4);           \
            if ((insert_previous_size & BLOCK_FLAG_2) == 0) {                                      \
                insert_previous =                                                                  \
                    (AllocatorBlock *)((unsigned char *)insert_block - insert_previous_size);      \
                insert_flags = insert_previous->size_flags & 7;                                    \
                insert_size = insert_previous_size + BlockSize(insert_block);                      \
                insert_previous->size_flags = insert_flags | (insert_size & BLOCK_SIZE_MASK);      \
                if ((insert_previous->size_flags & BLOCK_FLAG_2) == 0) {                           \
                    *(unsigned int *)((unsigned char *)insert_previous + insert_size - 4) =        \
                        insert_size;                                                               \
                }                                                                                  \
                if (FREE_LIST_SLOT(insert_area, insert_head_offset) == insert_block) {             \
                    FREE_LIST_SLOT(insert_area, insert_head_offset) = insert_block->next_free;     \
                }                                                                                  \
                UnlinkFreeBlock(insert_area, insert_head_offset, insert_block);                    \
                insert_block = insert_previous;                                                    \
                FREE_LIST_SLOT(insert_area, insert_head_offset) = insert_block;                    \
            }                                                                                      \
        }                                                                                          \
        insert_size = BlockSize(insert_block);                                                     \
        insert_following = (AllocatorBlock *)((unsigned char *)insert_block + insert_size);        \
        if ((insert_following->size_flags & BLOCK_FLAG_2) == 0) {                                  \
            insert_following_size = BlockSize(insert_following);                                   \
            insert_flags = insert_block->size_flags & 7;                                           \
            insert_size += insert_following_size;                                                  \
            insert_block->size_flags = insert_flags | (insert_size & BLOCK_SIZE_MASK);             \
            if ((insert_block->size_flags & BLOCK_FLAG_2) == 0) {                                  \
                *(unsigned int *)((unsigned char *)insert_block + insert_size - 4) = insert_size;  \
            }                                                                                      \
            if ((insert_block->size_flags & BLOCK_FLAG_2) == 0) {                                  \
                insert_following->size_flags &= ~BLOCK_FLAG_4;                                     \
            } else {                                                                               \
                insert_following->size_flags |= BLOCK_FLAG_4;                                      \
            }                                                                                      \
            if (FREE_LIST_SLOT(insert_area, insert_head_offset) == insert_following) {             \
                FREE_LIST_SLOT(insert_area, insert_head_offset) = insert_following->next_free;     \
            }                                                                                      \
            if (FREE_LIST_SLOT(insert_area, insert_head_offset) == insert_following) {             \
                FREE_LIST_SLOT(insert_area, insert_head_offset) = 0;                               \
            }                                                                                      \
            UnlinkFreeBlock(insert_area, insert_head_offset, insert_following);                    \
            FREE_LIST_SLOT(insert_area, insert_head_offset) = insert_block;                        \
        }                                                                                          \
        insert_size = BlockSize(FREE_LIST_SLOT(insert_area, insert_head_offset));                  \
        if (insert_area->largest_free_size < insert_size) {                                        \
            insert_area->largest_free_size = insert_size;                                          \
        }                                                                                          \
    } while (0)

#define SPLIT_ALLOCATOR_BLOCK(block_arg, size_arg)                                                 \
    do {                                                                                           \
        AllocatorBlock *split_block = (block_arg);                                                 \
        unsigned int split_size = (size_arg);                                                      \
        unsigned int split_old_size;                                                               \
        unsigned int split_old_flags;                                                              \
        unsigned int split_remaining_size;                                                         \
        unsigned int split_owner;                                                                  \
        AllocatorBlock *split_remaining;                                                           \
        AllocatorBlock *split_following;                                                           \
        split_old_size = BlockSize(split_block);                                                   \
        split_old_flags = split_block->size_flags;                                                 \
        split_owner = (split_block->tagged_area & ~1) | 1;                                         \
        split_remaining = (AllocatorBlock *)((unsigned char *)split_block + split_size);           \
        split_remaining_size = split_old_size - split_size;                                        \
        split_block->tagged_area = split_owner;                                                    \
        split_block->size_flags = split_size | (split_old_flags & BLOCK_FLAG_4);                   \
        if ((split_old_flags & BLOCK_FLAG_2) != 0) {                                               \
            split_block->size_flags |= BLOCK_FLAG_2;                                               \
        } else {                                                                                   \
            *(unsigned int *)((unsigned char *)split_remaining - 4) = split_size;                  \
        }                                                                                          \
        split_remaining->tagged_area = split_owner;                                                \
        split_remaining->size_flags = split_remaining_size;                                        \
        if ((split_old_flags & BLOCK_FLAG_2) != 0) {                                               \
            split_remaining->size_flags |= BLOCK_FLAG_4 | BLOCK_FLAG_2;                            \
        } else {                                                                                   \
            split_following =                                                                      \
                (AllocatorBlock *)((unsigned char *)split_remaining + split_remaining_size);       \
            *(unsigned int *)((unsigned char *)split_following - 4) = split_remaining_size;        \
        }                                                                                          \
        if ((split_old_flags & BLOCK_FLAG_2) != 0) {                                               \
            split_following =                                                                      \
                (AllocatorBlock *)((unsigned char *)split_remaining + split_remaining_size);       \
            split_following->size_flags |= BLOCK_FLAG_4;                                           \
        }                                                                                          \
        INSERT_FREE_BLOCK(BlockArea(split_block), split_remaining);                                \
    } while (0)

void *ALLOCATOR_RESIZE_FUNCTION(void *heap, void *ptr, unsigned int size) {
    AllocatorBlock *block;
    AllocatorBlock *following;
    unsigned int free_head_offset;
    AllocatorArea *area;
    void *owner;
    unsigned int old_size;
    unsigned int block_size;
    unsigned int required_size;
    unsigned int combined_size;
    void *new_ptr;

    if (ptr == 0) {
        return ALLOCATOR_ALLOCATE_HELPER(heap, size);
    }
    if (size == 0) {
        ALLOCATOR_RELEASE_HELPER(heap, ptr);
        return 0;
    }

    owner = *(void **)((unsigned char *)ptr - 4);
    if (((unsigned int)owner & 1) == 0) {
        old_size = *(unsigned int *)((unsigned char *)owner + 8);
    } else {
        block = (AllocatorBlock *)((unsigned char *)ptr - 8);
        old_size = BlockSize(block) - 8;
    }

    if (size > old_size) {
        if (((unsigned int)owner & 1) != 0) {
            if (size > 0xFFFFFFCF) {
                return 0;
            }

            required_size = (size + 0xF) & BLOCK_SIZE_MASK;
            if (required_size < MINIMUM_BLOCK_SIZE) {
                required_size = MINIMUM_BLOCK_SIZE;
            }
            block = (AllocatorBlock *)((unsigned char *)ptr - 8);
            block_size = BlockSize(block);
            area = BlockArea(block);
            free_head_offset = FreeListOffset(area);
            following = (AllocatorBlock *)((unsigned char *)block + block_size);
            if ((following->size_flags & BLOCK_FLAG_2) == 0) {
                combined_size = block_size + BlockSize(following);
                block->size_flags = (block->size_flags & 7) | (combined_size & BLOCK_SIZE_MASK);
                following = (AllocatorBlock *)((unsigned char *)block + combined_size);
                if ((block->size_flags & BLOCK_FLAG_2) == 0) {
                    *(unsigned int *)((unsigned char *)following - 4) = combined_size;
                    following->size_flags &= ~BLOCK_FLAG_4;
                } else {
                    following->size_flags |= BLOCK_FLAG_4;
                }
                UnlinkFreeBlock(area, free_head_offset,
                                (AllocatorBlock *)((unsigned char *)block + block_size));

                if (combined_size >= required_size) {
                    if (combined_size - required_size >= MINIMUM_BLOCK_SIZE) {
                        SPLIT_ALLOCATOR_BLOCK(block, required_size);
                    }
                    return ptr;
                }
            }
        }

        new_ptr = ALLOCATOR_ALLOCATE_HELPER(heap, size);
        if (new_ptr == 0) {
            return 0;
        }
        memcpy(new_ptr, ptr, old_size);
        ALLOCATOR_RELEASE_HELPER(heap, ptr);
        return new_ptr;
    }

    if (((unsigned int)owner & 1) != 0) {
        required_size = (size + 0xF) & BLOCK_SIZE_MASK;
        if (required_size < MINIMUM_BLOCK_SIZE) {
            required_size = MINIMUM_BLOCK_SIZE;
        }
        block = (AllocatorBlock *)((unsigned char *)ptr - 8);
        block_size = BlockSize(block);
        if (block_size - required_size >= MINIMUM_BLOCK_SIZE) {
            SPLIT_ALLOCATOR_BLOCK(block, required_size);
        }
    }
    return ptr;
}

#undef BLOCK_SIZE_MASK
#undef BLOCK_FLAG_2
#undef BLOCK_FLAG_4
#undef MINIMUM_BLOCK_SIZE
#undef FREE_LIST_SLOT
#undef INSERT_FREE_BLOCK
#undef SPLIT_ALLOCATOR_BLOCK

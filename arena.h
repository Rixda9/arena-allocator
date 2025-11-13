#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct {
    char *memory;
    size_t used;
    size_t capacity;
} Arena;

Arena* arena_create(size_t capacity);
void* arena_alloc(Arena *a, size_t size);
void arena_reset(Arena *a);
void arena_destroy(Arena *a);

#endif

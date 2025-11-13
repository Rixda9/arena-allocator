#include "arena.h"
#include <stdlib.h>

Arena *arena_create(size_t capacity) {

    Arena *a = malloc(sizeof(Arena));
    if (a == NULL) {
        return NULL;
    }
    a->memory = malloc(capacity);
    if (a->memory == NULL) {
        free(a);
        return NULL;
    }

    a->capacity = capacity;
    a->used = 0;

    return a;
}

void *arena_alloc(Arena *a, size_t size) {

    if (size > a->capacity - a->used) {
        return NULL;
    }

    void *result = a->memory + a->used;

    a->used += size;

    return result;

}

void arena_reset(Arena *a) {
    a->used = 0;
}

void arena_destroy(Arena *a) {
    free(a->memory);
    free(a);
}

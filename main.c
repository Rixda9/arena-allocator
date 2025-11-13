#include "arena.h"
#include <stdio.h>

int main (void) {

    Arena *a = arena_create(1024);

    if (a == NULL) {
        printf("Failed to create an arena\n");
        return 1;
    }

    printf("Arena created successfully!\nCapacity: %zu\nUsed: %zu\nMemory pointer: %p\n", a->capacity, a->used, (void*)a->memory);

    int *x = arena_alloc(a, sizeof(int));
    if (x == NULL) {
       printf("Failed to allocate\n");
       return 1;
    }
    *x = 42;
    printf("After first alloc: used=%zu\n", a->used);

    int *y = arena_alloc(a, sizeof(int));
    if (y == NULL) {
       printf("Failed to allocate\n");
       return 1;
    }
    *y = 99;
    printf("After second alloc: used=%zu\n", a->used);

    printf("x = %d, y = %d\n", *x, *y);


    char *test = arena_alloc(a, 2000);
    if (test == NULL) {
       printf("Correctly rejected allocation that would overflow\n");
    }

    printf("\nResetting the arena...\n");
    arena_reset(a);
    printf("After reset: used=%zu\n", a->used);

    int *z = arena_alloc(a, sizeof(int));
    *z = 123;
    printf("z = %d, used = %zu\n", *z, a->used);

    arena_destroy(a);
    printf("Arena destroyed!\n");


    return 0;
}

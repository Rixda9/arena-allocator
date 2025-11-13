# Arena Allocator

A simple arena/region-based memory allocator in C.

## About

I built this to learn how memory allocators work at a low level. An arena allocator is faster than malloc/free for short-lived objects because you allocate from a pre-allocated block and free everything at once.

## Usage
```c
Arena *a = arena_create(1024);
int *x = arena_alloc(a, sizeof(int));
arena_destroy(a);  // Frees everything
```

## Building
```bash
make
make test
```

## What I Learned

- How allocators manage memory internally
- Pointer arithmetic and bounds checking
- Why game engines and compilers use arena allocation
- Memory management patterns in C

## Use Cases

- Game engines (per-frame temp allocations)
- Compilers (temporary data)
- Parsers (AST nodes)

## API

**arena_create(capacity)** - Creates arena  
**arena_alloc(arena, size)** - Allocates memory  
**arena_reset(arena)** - Resets for reuse  
**arena_destroy(arena)** - Frees everything


**Author:** Rixda9

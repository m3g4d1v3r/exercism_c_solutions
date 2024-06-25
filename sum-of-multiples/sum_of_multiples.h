#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#define ARRAY_MAX 5000
#define TABLEMAX 1000
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct entry {
    unsigned int key;
    int value;
    struct entry *next;
} entry_t;

typedef struct hashmap {
    entry_t *array[TABLEMAX];
} hashmap_t;

size_t hash(const unsigned int key);
hashmap_t *hashmap_allocate();
hashmap_t *hashmap_create(entry_t *entry_array, size_t array_len);
void hashmap_free_all(hashmap_t *map);
entry_t *hashmap_get(hashmap_t *map, unsigned int key);
void hashmap_insert(hashmap_t *map, entry_t *new_entry);
void hashmap_write(hashmap_t *map, unsigned int key, int value);
void hashmap_print_all(hashmap_t *map);

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit);

#endif

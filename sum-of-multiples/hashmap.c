#include "hashmap.h"

size_t hash(unsigned int key) {
    size_t result_idx = 0;

    while (key > 1.0) {
        result_idx = result_idx * 37 + key % 10;
        key /= 10;
    }
    return (result_idx % TABLEMAX);
}

void hashmap_insert(hashmap_t *map, entry_t *new) {
    size_t new_idx;
    entry_t *ptr, **ptr_ptr;

    if (map == NULL || new == NULL) return;
    new_idx = hash(new->key);
    ptr_ptr = &map->array[new_idx];
    ptr = map->array[new_idx];
    while (ptr != NULL) {
        if (ptr->key == new->key) return;
        ptr_ptr = &ptr->next;
        ptr = ptr->next;
    }
    ptr = (entry_t *)malloc(sizeof(entry_t));
    ptr->key = new->key;
    ptr->value = new->value;
    ptr->next = NULL;
    *ptr_ptr = ptr;
}

void hashmap_write(hashmap_t *map, unsigned int key, int value) {
    size_t new_idx;
    entry_t *ptr, **ptr_ptr;

    if (map == NULL) return;
    new_idx = hash(key);
    ptr_ptr = &map->array[new_idx];
    ptr = map->array[new_idx];
    while (ptr != NULL) {
        if (ptr->key == key) return;
        ptr_ptr = &ptr->next;
        ptr = ptr->next;
    }
    ptr = (entry_t *)malloc(sizeof(entry_t));
    ptr->key = key;
    ptr->value = value;
    ptr->next = NULL;
    *ptr_ptr = ptr;
}

hashmap_t *hashmap_allocate() {
    hashmap_t *map = malloc(sizeof(hashmap_t));

    for (size_t idx = 0; idx < TABLEMAX; idx++) {
        map->array[idx] = NULL;
    }
    return (map);
}

hashmap_t *hashmap_create(entry_t *entry_array, size_t array_len) {
    hashmap_t *map = malloc(sizeof(hashmap_t));

    for (size_t idx = 0; idx < TABLEMAX; idx++) {
        map->array[idx] = NULL;
    }
    for (size_t idx = 0; idx < array_len; idx++) {
        hashmap_insert(map, &entry_array[idx]);
    }
    return (map);
}

entry_t *hashmap_get(hashmap_t *map, unsigned int key) {
    if (map == NULL) return NULL;
    return (map->array[hash(key)]);
}

void hashmap_print_all(hashmap_t *map) {
    for (size_t i = 0; i < TABLEMAX; i++) {
        entry_t *curr_entry = map->array[i];
        while (curr_entry != NULL) {
            printf("idx[%zu]\tcurr_entry [%ud]:\t%d\n", i, curr_entry->key,
                   curr_entry->value);
            curr_entry = curr_entry->next;
        }
    }
}

void hashmap_free_all(hashmap_t *map) {
    for (size_t i = 0; i < TABLEMAX; i++) {
        entry_t *curr_entry = map->array[i];
        while (curr_entry != NULL) {
            entry_t *temp = curr_entry;
            curr_entry = curr_entry->next;
            free(temp);
        }
    }
    free(map);
}

// int main() {
//     entry_t entry_array[] = {
//         {"apple", 10},  {"orange", 20}, {"oatmeal", 30}, {"chocolate", 40},
//         {"tea", 50},    {"coffee", 60}, {"energy", 70},  {"mushroom", 80},
//         {"banana", 90}, {"peach", 100}, {"water", 110}};
//     size_t array_len = sizeof(entry_array) / sizeof(entry_t);
//
//     hashmap_t *map = hashmap_create(entry_array, array_len);
//     hashmap_print_all(map);
//     entry_t *item = hashmap_get(map, "water");
//     if (item != NULL) {
//         printf("entry found!\n");
//         printf("key: %s, value: %d\n", item->key, item->value);
//     }
//     hashmap_free_all(map);
//     return (0);
// }

#include <stdio.h>
#include <stdlib.h>

#include "map.h"

void clara_map_init(ClaraMap *map, size_t size) {
    map->size  = size;
    map->items = calloc(CLARA_MAP_INIT_SIZE, sizeof(*map->items));
}

size_t clara_map_hash(const ClaraMap *const map, const char *key) {
    size_t h = 5381;

    while (*key)
        h = h * 101 + (size_t)*key++;

    return h % map->size;
}

void clara_map_set(ClaraMap *map, char *key, char *value) {
    ClaraMapNode *node = malloc(sizeof(*node));

    node->key = key;
    node->val = value;

    map->items[clara_map_hash(map, key)] = node;
}

ClaraMapNode *clara_map_get(ClaraMap *map, char *key) {
    return map->items[clara_map_hash(map, key)];
}

void clara_map_destruct(ClaraMap *map) {
    size_t idx;

    for (idx = 0; idx < map->size; ++idx)
        free(map->items[idx]);

    free(map->items);

    map->size = 0;
}

void clara_map_print(const ClaraMap *const map) {
    size_t idx;

    printf("size ( capacity ) = %lu\n", map->size);

    for (idx = 0; idx < map->size; ++idx) {
        if (map->items[idx])
            printf("  %lu | %s | %s\n", idx, map->items[idx]->key,
                   map->items[idx]->val);
    }
}

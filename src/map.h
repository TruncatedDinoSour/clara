#ifndef _CLARA_MAP_H
#define _CLARA_MAP_H
#include <stddef.h>

#define CLARA_MAP_INIT_SIZE 16

typedef struct ClaraMapNode {
    const char *key;
    const char *val;
} ClaraMapNode;

typedef struct {
    size_t size;
    ClaraMapNode **items;
} ClaraMap;

void clara_map_init(ClaraMap *map, size_t size);
size_t clara_map_hash(const ClaraMap *const map, const char *key);
void clara_map_set(ClaraMap *map, char *key, char *value);
ClaraMapNode *clara_map_get(ClaraMap *map, char *key);
void clara_map_destruct(ClaraMap *map);
void clara_map_print(const ClaraMap *const map);
#endif /* _CLARA_MAP_H */

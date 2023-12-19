#include <stdio.h>

#include "main.h"
#include "map.h"

int main(void) {
    ClaraMap map;
    ClaraMapNode *node;

    clara_map_init(&map, 16);
    clara_map_set(&map, "hello world !", "hello :)");
    node = clara_map_get(&map, "hello world !");
    printf("%s\n", node ? node->val : "NONE");
    node = clara_map_get(&map, "hello waorld !");
    printf("%s\n", node ? node->val : "NONE");
    clara_map_print(&map);
    clara_map_destruct(&map);

    return 0;
}

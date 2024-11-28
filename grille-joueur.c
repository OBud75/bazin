#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    struct Block *top;
    struct Block *right;
    struct Block *bottom;
    struct Block *left;
    int x, y;
} Block;

typedef struct {
    Block *position;
} Player;

typedef struct {
    Block **blocks;
    int width;
    int height;
} Map;

Map* get_map(int width, int height) {
    Map *map = (Map *)malloc(sizeof(Map));
    map->width = width;
    map->height = height;
    map->blocks = (Block **)malloc(width * height * sizeof(Block *));

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            map->blocks[i * height + j] = (Block *)malloc(sizeof(Block));
            map->blocks[i * height + j]->top = NULL;
            map->blocks[i * height + j]->right = NULL;
            map->blocks[i * height + j]->bottom = NULL;
            map->blocks[i * height + j]->left = NULL;
            map->blocks[i * height + j]->x = i;
            map->blocks[i * height + j]->y = j;
        }
    }

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (i > 0)
                map->blocks[i * height + j]->left = map->blocks[(i - 1) * height + j];
            if (i < width - 1)
                map->blocks[i * height + j]->right = map->blocks[(i + 1) * height + j];
            if (j > 0)
                map->blocks[i * height + j]->top = map->blocks[i * height + (j - 1)];
            if (j < height - 1)
                map->blocks[i * height + j]->bottom = map->blocks[i * height + (j + 1)];
        }
    }

    return map;
}

void move(Player *player, char direction) {
    if (direction == 'U' && player->position->top != NULL) {
        player->position = player->position->top;
        printf("Player moved up to (%d, %d)\n", player->position->x, player->position->y);
    } else if (direction == 'R' && player->position->right != NULL) {
        player->position = player->position->right;
        printf("Player moved right to (%d, %d)\n", player->position->x, player->position->y);
    } else if (direction == 'D' && player->position->bottom != NULL) {
        player->position = player->position->bottom;
        printf("Player moved down to (%d, %d)\n", player->position->x, player->position->y);
    } else if (direction == 'L' && player->position->left != NULL) {
        player->position = player->position->left;
        printf("Player moved left to (%d, %d)\n", player->position->x, player->position->y);
    } else {
        printf("Movement not possible in the specified direction.\n");
    }
}

void free_map(Map *map) {
    for (int i = 0; i < map->width * map->height; ++i) {
        free(map->blocks[i]);
    }
    free(map->blocks);
    free(map);
}

void print_map(Map *map, Player *player) {
    for (int j = 0; j < map->height; ++j) {
        for (int i = 0; i < map->width; ++i) {
            if (player->position == map->blocks[i * map->height + j]) {
                printf("P ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int width = 5;
    int height = 5;

    Map *map = get_map(width, height);
    Player player = {map->blocks[0]};

    printf("Initial map:\n");
    print_map(map, &player);

    move(&player, 'R');
    print_map(map, &player);
    move(&player, 'D');
    print_map(map, &player);
    move(&player, 'D');
    print_map(map, &player);
    move(&player, 'L');
    print_map(map, &player);
    move(&player, 'U');
    print_map(map, &player);

    free_map(map);

    return 0;
}

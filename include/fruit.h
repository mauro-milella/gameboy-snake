#ifndef FRUIT_H
#define FRUIT_H

#include <generics.h>

#define FRUIT_TILE_ID 2

extern unsigned char fruit_sprite[16];

struct fruit {
    struct coordinate position;
    uint8_t score_reward;

    uint8_t sprite_id;
    uint8_t sprite_tile;
};

void initialize_fruit(struct fruit* fruit);

void place(struct fruit* fruit);
uint8_t pickup(struct fruit* fruit, struct coordinate* position);

void draw_fruit(struct fruit* fruit);

#endif
#ifndef SNAKE_H
#define SNAKE_H

#include <gb/gb.h>

#include <generics.h>

struct snake {
    struct coordinate position;

    int8_vector2 head_direction;

    uint8_t sprite_id;
    unsigned char snake_head_sprite[16];
    unsigned char snake_body_sprite[16];

    // TODO - implement the tail
};

void initialize(struct snake* snake);

#endif
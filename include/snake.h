#ifndef SNAKE_H
#define SNAKE_H

#include <gb/gb.h>

#include <generics.h>

#define SNAKE_MAX_SIZE 180
#define SNAKE_INIT_SIZE 5

struct snake {
    struct coordinate position;
    struct coordinate prev_position;
    int8_vector2 direction;

    struct coordinate tail_cells[SNAKE_MAX_SIZE];
    uint8_t tail_size;

    uint8_t sprite_id[2];
};

void initialize(struct snake* snake);

void move_head(struct snake* snake, int8_vector2* delta_pos);

// Returns 0 if any tail's cell overlaps with snake's head, 1 otherwise.
uint8_t move_tail(struct snake* snake);

void draw(struct snake* snake);

#endif
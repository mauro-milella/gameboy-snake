#ifndef SNAKE_H
#define SNAKE_H

#include <gb/gb.h>

#include <generics.h>

// The ids in the range [0,30] are reserved for drawing the snake
// (head + n. of tail cells)
#define SNAKE_MAX_SIZE 31
#define SNAKE_INIT_SIZE 5

#define HEAD_TILE_ID 0
#define BODY_TILE_ID 1

extern unsigned char snake_head_sprite[16];
extern unsigned char snake_tail_sprite[16];

struct snake {
    // Head current and previous position, and direction of movement
    struct coordinate position;
    struct coordinate prev_position;
    int8_vector2 direction;

    // Tail
    struct coordinate tail_cells[SNAKE_MAX_SIZE];
    uint8_t tail_size;

    // Drawing
    uint8_t sprite_id[SNAKE_MAX_SIZE];
    uint8_t sprite_tile[2];
};

void initialize_snake(struct snake* snake);

void move_head(struct snake* snake, int8_vector2* delta_pos);

// Returns 0 if any tail's cell overlaps with snake's head, 1 otherwise.
uint8_t move_tail(struct snake* snake);

void draw_snake(struct snake* snake);

#endif
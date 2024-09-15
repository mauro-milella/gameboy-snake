#ifndef INTERACTION_H
#define INTERACTION_H

#include <gb/gb.h>

struct coordinate {
    int8_t x;
    int8_t y;
};

/*
Handle joypad input;
e.g.: update velocities.
*/
void jopyad_input(uint8_t* joypad_current, struct coordinate* delta_pos);

/*
This is specifically designed to move the snake safely;
the new direction proposed by `joypad_input` is validated and then applied.
*/
void move(uint8_t sprite_id, uint8_t* snake_x, uint8_t* snake_y, int8_t* direction_x, int8_t* direction_y, struct coordinate* delta_pos);

/*
This function makes a sprite bounce all over the window, and it's just an experiment.
If a screen border is touched, bounce on the opposite direction.
Maybe, the fruit could jump around with its own trajectory while you follow it.
*/
void auto_bouncy_interaction(
    uint8_t* sprite_x,
    uint8_t* sprite_y,
    int8_t* velocity_x,
    int8_t* velocity_y);

#endif
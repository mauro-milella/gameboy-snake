#ifndef INTERACTION_H
#define INTERACTION_H

#include <snake.h>

/*
Handle joypad input;
e.g.: update velocities.
*/
void jopyad_input(uint8_t* joypad_current, int8_vector2* delta_pos);

/*
This is specifically designed to move the snake safely;
the new direction proposed by `joypad_input` is validated and then applied.
*/
void move(struct snake* snake, int8_vector2* delta_pos);

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
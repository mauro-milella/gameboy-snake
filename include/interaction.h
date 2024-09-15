#ifndef INTERACTION_H
#define INTERACTION_H

#include <generics.h>

/*
Handle joypad input;
e.g.: update velocities.
*/
void jopyad_input(uint8_t* joypad_current, int8_vector2* delta_pos);

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
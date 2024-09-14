#ifndef INTERACTION_H
#define INTERACTION_H

#include <gb/gb.h>

/*
Update sprite position depending on velocity.
If a screen border is touched, bounce on the opposite direction.
*/
void auto_bouncy_interaction(
    uint8_t* sprite_x,
    uint8_t* sprite_y,
    int8_t* velocity_x,
    int8_t* velocity_y);

/*
Handle joypad input;
e.g.: update velocities.
*/
void jopyad_input(
    uint8_t* joypad_current,
    uint8_t* joypad_previous,
    int8_t* velocity_x, 
    int8_t* velocity_y);

#endif
#include <gb/gb.h>
#include "screen.h"
#include "audio.h"

void jopyad_input(
    uint8_t* joypad_current,
    uint8_t* joypad_previous,
    int8_t* direction_x, 
    int8_t* direction_y)
{
    int8_t delta_x = 0, delta_y = 0;
    uint8_t moved = 0;

    (*joypad_current) = joypad();

    // The snake cannot move in the opposite direction he is facing
    if (((*joypad_current) & J_RIGHT) && !((*joypad_previous) & J_LEFT)) {
        delta_x = 1;
        moved = 1;
    } 
    if (((*joypad_current) & J_DOWN) && !((*joypad_previous) & J_UP)) {
        delta_y = 1;
        moved = 1;
    } 
    if (((*joypad_current) & J_LEFT) && !((*joypad_previous) & J_RIGHT)) {
        delta_x = -1;
        moved = 1;
    } 
    if (((*joypad_current) & J_UP) && !((*joypad_previous) & J_DOWN)) {
        delta_y = -1;
        moved = 1;
    }

    // A-B buttons - just make a sound
    if ((*joypad_current & J_A) && !(*joypad_previous & J_A)) {
        play_sound_1();
    } else if ((*joypad_current & J_B) && !(*joypad_previous & J_B)) {
        play_sound_2();
    }

    // Remember a previous input only if the movement is effectively triggered
    if (moved) {
        (*joypad_previous) = (*joypad_current);
    }

    // Update only if a direction is choosen, otherwise just move as before
    int8_t _speed = delta_x + delta_y;
    if (_speed < 0) {
        _speed *= -1;
    }

    if (_speed == 1) {
        (*direction_x) = delta_x;
        (*direction_y) = delta_y;
    }
}

void auto_bouncy_interaction(
    uint8_t* sprite_x,
    uint8_t* sprite_y,
    int8_t* velocity_x,
    int8_t* velocity_y)
{
    (*sprite_x) += (*velocity_x);
    (*sprite_y) += (*velocity_y);
    
    // Too far to the right
    if ((*sprite_x) > HI_BOUND_X && (*velocity_x) > 0) {
        (*velocity_x) = -(*velocity_x);
        (*sprite_x) = HI_BOUND_X;
    }

    // Too far down while moving downwards
    if ((*sprite_y) > HI_BOUND_Y && (*velocity_y) > 0) {
        (*velocity_y) = -(*velocity_y);
        (*sprite_y) = HI_BOUND_Y;
        (*velocity_x) = 1;
    }
    
    // Too far to the left
    if ((*sprite_x) < LO_BOUND_X && (*velocity_x) < 0) {
        (*velocity_x) = -(*velocity_x);
        (*sprite_x) = LO_BOUND_X;
    }

    // Too far to the top
    if ((*sprite_y) < LO_BOUND_Y && (*velocity_y) < 0) {
        (*velocity_y) = -(*velocity_y);
        (*sprite_y) = LO_BOUND_Y;
    }
}

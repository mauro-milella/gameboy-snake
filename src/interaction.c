#include <gb/gb.h>
#include "screen.h"
#include "audio.h"

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

void jopyad_input(
    uint8_t* joypad_current,
    uint8_t* joypad_previous,
    int8_t* velocity_x, 
    int8_t* velocity_y)
{
    // Velocity is modified at the end, to make interaction smoother
    uint8_t interaction = 0;
    int8_t delta_x = 0, delta_y = 0;

    (*joypad_previous) = (*joypad_current);
    (*joypad_current) = joypad();

    // Arrow buttons
    if ((*joypad_current) & J_RIGHT) {
        delta_x += 1;
        interaction = 1;
    } 
    if ((*joypad_current) & J_DOWN) {
        delta_y = 1;
        interaction = 1;
    } 
    if ((*joypad_current) & J_LEFT) {
        delta_x += -1;
        interaction = 1;
    } 
    if ((*joypad_current) & J_UP) {
        delta_y = -1;
        interaction = 1;
    } 

    if (!interaction) {
        delta_x = delta_y = 0;
    }

    // A-B buttons
    if ((*joypad_current & J_A) && !(*joypad_previous & J_A)) {
        play_sound_1();
    } else if ((*joypad_current & J_B) && !(*joypad_previous & J_B)) {
        play_sound_2();
    }

    (*velocity_x) = delta_x;
    (*velocity_y) = delta_y;
}
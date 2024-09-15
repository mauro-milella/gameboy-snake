#include <gb/gb.h>

#include <audio.h>
#include <generics.h>
#include <interaction.h>
#include <screen.h>
#include <snake.h>

void jopyad_input(uint8_t* joypad_current, struct coordinate* delta_pos)
{
    int8_t delta_x = 0, delta_y = 0;

    (*joypad_current) = joypad();

    if (*joypad_current & J_RIGHT) {
        delta_x = 1;
    } 
    if (*joypad_current & J_DOWN) {
        delta_y = 1;
    } 
    if (*joypad_current & J_LEFT) {
        delta_x = -1;
    } 
    if (*joypad_current & J_UP) {
        delta_y = -1;
    }

    // A-B buttons could do a special action;
    // for now, a sound is reproduced (this can be spammed).
    if (*joypad_current & J_A) {
        play_sound_1();
    } else if (*joypad_current & J_B) {
        play_sound_2();
    }

    // Update only if a direction is choosen, otherwise just move as before
    int8_t _speed = delta_x + delta_y;

    if (_speed < 0) {
        _speed = -_speed;
    }

    if (_speed == 1) {
        delta_pos->x = delta_x;
        delta_pos->y = delta_y;
    }
}

void move(struct snake* snake, struct coordinate* delta_pos)
{
    if (delta_pos->x != -snake->head_direction_x && 
        delta_pos->y != -snake->head_direction_y) {
        snake->head_direction_x = delta_pos->x;
        snake->head_direction_y = delta_pos->y;
    }

    snake->position.x = snake->head_direction_x*8;
    snake->position.y = snake->head_direction_y*8;

    move_sprite(
        snake->sprite_id, 
        snake->position.x+DX_CORRECTION, 
        snake->position.y+DY_CORRECTION);
    
    pacman_effect(snake);
}

// Deprecated
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

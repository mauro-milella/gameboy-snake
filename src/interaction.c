#include <gb/gb.h>

#include <audio.h>
#include <generics.h>
#include <interaction.h>
#include <screen.h>

void jopyad_input(uint8_t* joypad_current, int8_vector2* delta_pos)
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
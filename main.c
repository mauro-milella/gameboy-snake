#include <gb/gb.h>

#include "audio.h"
#include "interaction.h"
#include "snake_sprites.h"
#include "screen.h"

uint8_t sprite_x, sprite_y;
int8_t velocity_x, velocity_y;
uint8_t joypad_current=0, joypad_previous=0;

void main(void)
{
    // Audio initialization
    audio_simple_init();

    // Display initialization
    DISPLAY_ON;
    SHOW_SPRITES;

    // Snake head initialization
    uint8_t sprite_id = 0;
    sprite_x = 80;
    sprite_y = 70;

    set_sprite_data(sprite_id, 1, snake_head_sprite);
    set_sprite_tile(sprite_id, 0);
    move_sprite(sprite_id, sprite_x, sprite_y);

    // Main game loop
    while (1) {
        // Manage movement
        jopyad_input(&joypad_current, &joypad_previous, &velocity_x, &velocity_y);
        sprite_x += velocity_x;
        sprite_y += velocity_y;

        move_sprite(sprite_id, sprite_x+DX_CORRECTION, sprite_y+DY_CORRECTION);

        // Halt until next frame
        vsync();
    }
}

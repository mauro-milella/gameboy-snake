#include <gb/gb.h>
#include <time.h>

#include "audio.h"
#include "interaction.h"
#include "snake_sprites.h"
#include "screen.h"

void main(void)
{
    // Audio initialization
    audio_simple_init();

    // Display initialization
    DISPLAY_ON;
    SHOW_SPRITES;
    SPRITES_8x8;

    // Gameplay initialization
    uint8_t snake_x, snake_y;
    int8_t direction_x=0, direction_y=0;
    uint8_t joypad_current=0, joypad_previous=0;

    // Snake head initialization
    uint8_t sprite_id = 0;
    snake_x = SCREENWIDTH/2;
    snake_y = SCREENHEIGHT/2;

    set_sprite_data(sprite_id, 1, snake_head_sprite);
    set_sprite_tile(sprite_id, 0);
    move_sprite(sprite_id, snake_x, snake_y);

    // Main game loop
    while (1) {
        // Manage movement when it is time to do so
        if ( ###condition on time here### ) {

            jopyad_input(&joypad_current, &joypad_previous, &direction_x, &direction_y);
            snake_x += direction_x+4;
            snake_y += direction_y+4;

            move_sprite(sprite_id, snake_x+DX_CORRECTION, snake_y+DY_CORRECTION);
        }

        // Halt until next frame
        vsync();
    }
}

#include <gb/gb.h>
#include <time.h>

#include <audio.h>
#include <interaction.h>
#include <snake_sprites.h>
#include <screen.h>

void main(void)
{
    // Gameboy initialization
    audio_simple_init();

    DISPLAY_ON;
    SHOW_SPRITES;
    SPRITES_8x8;

    uint8_t joypad_current=0;
    uint8_t elapsed_frames = 0;

    // Gameplay initialization
    uint8_t snake_x = 80, snake_y = 72;
    int8_t direction_x=1, direction_y=0;
    uint8_t sprite_id = 0;
    struct coordinate delta_pos = {.x = 0, .y = 0};

    set_sprite_data(sprite_id, 1, snake_head_sprite);
    set_sprite_tile(sprite_id, 0);
    move_sprite(sprite_id, snake_x, snake_y);

    // Main game loop
    while (1) {
        ++elapsed_frames;

        jopyad_input(&joypad_current, &delta_pos);
        
        // Manage movement when it is time to do so
        if (elapsed_frames > REFRESH_FACTOR) {
            elapsed_frames = 0;
            move(sprite_id, &snake_x, &snake_y, &direction_x, &direction_y, &delta_pos);
        }

        // Halt until next frame
        vsync();
    }
}

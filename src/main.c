#include <gb/gb.h>

#include <audio.h>
#include <interaction.h>
#include <screen.h>
#include <snake.h>
#include <snake_sprites.h>

#include <time.h>
#include <stdio.h>

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
    struct snake snake;
    initialize(&snake);

    int8_vector2 delta_pos = {.x = 0, .y = 0};

    set_sprite_data(0, 1, snake_head_sprite);
    set_sprite_data(1, 1, snake_tail_sprite);

    set_sprite_tile(snake.sprite_id[0], 0);
    move_sprite(snake.sprite_id[0], snake.position.x, snake.position.y);

    // Main game loop
    while (1) {
        ++elapsed_frames;

        jopyad_input(&joypad_current, &delta_pos);
        
        // Manage movement when it is time to do so
        if (elapsed_frames > REFRESH_FACTOR) {
            elapsed_frames = 0;
            
            move_head(&snake, &delta_pos);
            
            if (move_tail(&snake) == 0) {
                printf("Game over\n");
            }

            draw(&snake);
        }

        // Halt until next frame
        vsync();
    }
}

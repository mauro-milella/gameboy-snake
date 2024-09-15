#include <gb/gb.h>
#include <time.h>

#include <audio.h>
#include <interaction.h>
#include <screen.h>
#include <snake.h>

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

    set_sprite_data(snake.sprite_id, 1, snake.snake_head_sprite);
    set_sprite_tile(snake.sprite_id, 0);

    move_sprite(snake.sprite_id, snake.position.x, snake.position.y);

    // Main game loop
    while (1) {
        ++elapsed_frames;

        jopyad_input(&joypad_current, &delta_pos);
        
        // Manage movement when it is time to do so
        if (elapsed_frames > REFRESH_FACTOR) {
            elapsed_frames = 0;
            move(&snake, &delta_pos);
        }

        // Halt until next frame
        vsync();
    }
}

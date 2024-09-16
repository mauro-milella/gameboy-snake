#include <gb/gb.h>

#include <audio.h>
#include <fruit.h>
#include <interaction.h>
#include <screen.h>
#include <snake.h>

#include <time.h>
#include <stdio.h>

uint8_t play(void);

void main(void)
{
    // Gameboy initialization
    audio_simple_init();

    DISPLAY_ON;
    SHOW_SPRITES;
    SPRITES_8x8;

    while (1)
    {
        play();
        waitpad(J_A);
    }
    
}

uint8_t play(void)
{
    uint8_t joypad_current=0;
    uint8_t elapsed_frames = 0;

    // Gameplay initialization
    struct snake snake;
    initialize_snake(&snake);
    move_sprite(snake.sprite_id[0], snake.position.x, snake.position.y);

    struct fruit fruit;
    initialize_fruit(&fruit);

    int8_vector2 delta_pos = {.x = 0, .y = 0}; // Continuously updated by `joypad_input`

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
                return 0;
            }

            draw_snake(&snake);
            draw_fruit(&fruit);
        }

        // Halt until next frame
        vsync();
    }
}
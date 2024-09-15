#include <snake.h>
#include <snake_sprites.h>

extern struct snake;

void initialize(struct snake* snake) 
{
    snake->position.x = 80;
    snake->position.y = 72;

    snake->head_direction.x = 1;
    snake->head_direction.y = 0;

    snake->sprite_id = 0;

    for (int i=0; i<16; i++) {
        snake->snake_head_sprite[i] = snake_head_sprite[i];
        snake->snake_body_sprite[i] = snake_body_sprite[i];
    }
}
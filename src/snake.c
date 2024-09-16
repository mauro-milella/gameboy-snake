#include <screen.h>
#include <snake.h>

unsigned char snake_head_sprite[16] = 
{
    0x3C,0x3C,0x42,0x42,0x81,0x81,0xA5,0xA5,
    0x81,0x81,0x81,0xA5,0x42,0x5A,0x3C,0x3C
};

unsigned char snake_tail_sprite[16] = 
{
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

void initialize_snake(struct snake* snake) 
{
    snake->position.x = snake->prev_position.x = 80;
    snake->position.y = snake->prev_position.y = 72;

    snake->direction.x = 1;
    snake->direction.y = 0;

    // This way of iterating is not recommended by docs,
    // but should do its work for those few iterations.
    snake->tail_size = SNAKE_INIT_SIZE;
    snake->tail_cells[0].x = snake->position.x - 8;
    snake->tail_cells[0].y = snake->position.y - 8;
    for (uint8_t i=0; i<SNAKE_INIT_SIZE; i++) {
        snake->tail_cells[i].x = snake->tail_cells[i-1].x - 8;
        snake->tail_cells[i].y = snake->tail_cells[i-1].y - 8;
    }

    // Head and cell sprite ids
    set_sprite_data(HEAD_TILE_ID, 1, snake_head_sprite);
    set_sprite_data(BODY_TILE_ID, 1, snake_tail_sprite);
    
    snake->sprite_id[0] = 0;
    for (uint8_t i=1; i<SNAKE_MAX_SIZE; i++) {
        snake->sprite_id[i] = i;
    }
}

void move_head(struct snake* snake, int8_vector2* delta_pos)
{
    if (delta_pos->x != -snake->direction.x && 
        delta_pos->y != -snake->direction.y) {
        snake->direction.x = delta_pos->x;
        snake->direction.y = delta_pos->y;
    }

    snake->prev_position.x = snake->position.x;
    snake->prev_position.y = snake->position.y;

    snake->position.x += snake->direction.x*8;
    snake->position.y += snake->direction.y*8;

    pacman_effect(&snake->position.x, &snake->position.y);
}

uint8_t move_tail(struct snake* snake)
{
    for (uint8_t i=snake->tail_size; i>0; i--) {
        snake->tail_cells[i].x = snake->tail_cells[i-1].x;
        snake->tail_cells[i].y = snake->tail_cells[i-1].y;

        if (snake->tail_cells[i].x == snake->position.x &&
            snake->tail_cells[i].y == snake->position.y) {
            return 0;
        }
    }

    // It is impossible for a snake to collide with its own neck (the first tail cell)
    snake->tail_cells[0].x = snake->prev_position.x;
    snake->tail_cells[0].y = snake->prev_position.y;

    return 1;
}

void draw_snake(struct snake* snake)
{
    for (int i=0; i<snake->tail_size+1; i++) {
        set_sprite_tile(snake->sprite_id[i], i>0 && i<=snake->tail_size);

        move_sprite(
            snake->sprite_id[i],
            snake->tail_cells[i].x+DX_CORRECTION,
            snake->tail_cells[i].y+DY_CORRECTION
        );
    }
}
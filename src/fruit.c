#include <gb/gb.h>
#include <fruit.h>
#include <generics.h>
#include <screen.h>

#include <rand.h>

unsigned char fruit_sprite[] =
{
  0x06, 0x04, 0x0A, 0x1E, 0x3C, 0x3C, 0x5E, 0x6E, 
  0x7E, 0x5E, 0x7E, 0x7E, 0x3C, 0x3C, 0x10, 0x10
};

void initialize_fruit(struct fruit* fruit)
{
    initrand((uint8_t)GAME_SEED);

    place(fruit);

    fruit->score_reward = 1;

    fruit->sprite_id = 31; // Keep in mind that those between 0 and 30 are already reserved!
    set_sprite_data(FRUIT_TILE_ID, 1, fruit_sprite);
}

void place(struct fruit* fruit)
{
    // Consider a 16x18 grid.
    // Choose a random cell (row in [0,15], col in [0-17]),
    // then convert the cell to an actual position.

    uint8_t row = (uint8_t)rand() % 16;
    uint8_t col = (uint8_t)rand() % 18;

    fruit->position.x = col*8;
    fruit->position.y = row*8;
}

uint8_t pickup(struct fruit* fruit, struct coordinate* position)
{
    if (fruit->position.x == position->x && fruit->position.y == position->y) {
        return (uint8_t)1;
    }

    return (uint8_t)0;
}

void draw_fruit(struct fruit* fruit) 
{
    set_sprite_tile(fruit->sprite_id, 2);
    
    move_sprite(
        fruit->sprite_id,
        fruit->position.x+DX_CORRECTION,        
        fruit->position.y+DY_CORRECTION
    );
}

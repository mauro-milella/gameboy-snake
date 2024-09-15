#include <gb/gb.h>

#include <screen.h>
#include <snake.h>

void pacman_effect(struct snake* snake) {
    if (snake->position.x <= LO_BOUND_X) {
        snake->position.x = HI_BOUND_X;
    } 
    else if (snake->position.x >= HI_BOUND_X)
    {
        snake->position.x = LO_BOUND_X;
    }
    
    if (snake->position.y < LO_BOUND_Y) {
        snake->position.y = HI_BOUND_Y;
    } 
    else if (snake->position.y > HI_BOUND_Y)
    {
        snake->position.y = LO_BOUND_Y;
    }
}
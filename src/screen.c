#include <gb/gb.h>

#include <screen.h>
#include <snake.h>

void pacman_effect(uint8_t* x, uint8_t* y) {
    if (*x == LO_BOUND_X) {
        *x = HI_BOUND_X;
    } 
    else if (*x > HI_BOUND_X)
    {
        *x = LO_BOUND_X;
    }
    
    if (*y == LO_BOUND_Y) {
        *y = HI_BOUND_Y;
    } 
    else if (*y > HI_BOUND_Y)
    {
        *y = LO_BOUND_Y;
    }
}
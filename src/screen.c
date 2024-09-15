#include <gb/gb.h>
#include <screen.h>

void pacman_effect(uint8_t* x, uint8_t* y) {
    if ((*x) < LO_BOUND_X) {
        (*x) = HI_BOUND_X-HALF_SPRITE;
    } 
    else if ((*x) > HI_BOUND_X)
    {
        (*x) = LO_BOUND_X+HALF_SPRITE;
    }
    
    if ((*y) < LO_BOUND_Y) {
        (*y) = HI_BOUND_Y-HALF_SPRITE;
    } 
    else if ((*y) > HI_BOUND_Y)
    {
        (*y) = LO_BOUND_Y+HALF_SPRITE;
    }
}
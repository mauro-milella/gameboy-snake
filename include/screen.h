#ifndef SCREEN_H
#define SCREEN_H

/*
Number of vsync() calls that must pass before computing certain discretized actions;
for example, snake's movement.
The lower the factor, the faster is the game, hence, harder.
*/
#define REFRESH_FACTOR 30
#define MINIMUM_REFRESH_FACTOR 7

/*
Screen resolution is 160x144;
since each sprite is an 8x8 tile, those values are necessary to clip it.
*/
#define LO_BOUND_X 8
#define HI_BOUND_X 152
#define LO_BOUND_Y 16
#define HI_BOUND_Y 144

/*
Sprite rendering coordinates correction.
All sprites are rendered 8px to the left of their actual x position,
and 16 px above their actual y position, hence, sprites at 0x0 are not visible.
*/
#define DX_CORRECTION 4
#define DY_CORRECTION 12

#define SPRITE_SIZE 8
#define HALF_SPRITE_SIZE 4

void pacman_effect(uint8_t* x, uint8_t* y);

#endif
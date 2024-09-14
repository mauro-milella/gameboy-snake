#ifndef SCREEN_H
#define SCREEN_H

/*
Screen resolution is 160x144;
since each sprite is an 8x8 tile, those values are necessary to clip it.
*/
#define LO_BOUND_X 4
#define HI_BOUND_X 156
#define LO_BOUND_Y 4
#define HI_BOUND_Y 140

/*
Sprite rendering coordinates correction.
All sprites are rendered 8px to the left of their actual x position,
and 16 px above their actual y position, hence, sprites at 0x0 are not visible.
*/
#define DX_CORRECTION 4
#define DY_CORRECTION 12

#endif
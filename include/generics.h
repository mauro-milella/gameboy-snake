#ifndef GENERICS_H
#define GENERICS_H

#include <gb/gb.h>

#define GAME_SEED 111

struct coordinate {
    uint8_t x;
    uint8_t y;
};

typedef struct int8_vector2 {
    int8_t x;
    int8_t y;
} int8_vector2;

#endif
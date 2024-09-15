#include <gb/gb.h>

// Audio initialization: keep the order as is!
void audio_simple_init() {
    NR52_REG = 0x80; // Turns on sound
    NR50_REG = 0x77; // Set volume to max
    NR51_REG = 0xFF; // Select all the four audio channels for both left and right
}

void play_sound_1() {
    NR10_REG=0X00;
    NR11_REG=0X81;
    NR12_REG=0X43;
    NR13_REG=0X73;
    NR14_REG=0X86;
}

void play_sound_2() {
    NR10_REG=0X00;
    NR11_REG=0X81;
    NR12_REG=0X43;
    NR13_REG=0X73;
    NR14_REG=0X86;
}
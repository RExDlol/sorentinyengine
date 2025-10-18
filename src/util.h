#ifndef UTIL_H
#define UTIL_H

#include <SDL3/SDL.h>
#include <string.h>

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} Color;

extern Color col_white;
extern Color col_black;
extern Color col_gray;
extern Color col_red;
extern Color col_green;
extern Color col_blue;
extern Color col_yellow;
extern Color col_cyan;
extern Color col_magenta;


extern Color col_soft_red;
extern Color col_soft_green;
extern Color col_soft_blue;
extern Color col_soft_purple;
extern Color col_soft_yellow;
extern Color col_soft_cyan;


extern Color col_neon_pink;
extern Color col_neon_blue;
extern Color col_neon_green;
extern Color col_neon_purple;
extern Color col_neon_orange;


extern Color col_dark_bg;
extern Color col_light_bg;
extern Color col_ui_highlight;
extern Color col_ui_shadow;

#endif

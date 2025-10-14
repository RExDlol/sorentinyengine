#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <SDL3/SDL.h>

typedef struct {
    bool keys[SDL_SCANCODE_COUNT];
    int mouse_x, mouse_y;
    bool mouse_left;
    bool mouse_right;
} INP_Context;

void input_update(INP_Context *input);
bool key_pressed(INP_Context *input, SDL_Scancode key);

#endif
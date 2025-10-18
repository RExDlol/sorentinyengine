#include "input.h"


void input_init(INP_Context *input) {
    memset(input->keys, 0, sizeof(input->keys));
    input->mouse_left = false;
    input->mouse_right = false;
}
/* update of the input system */
void input_update(INP_Context *input) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_EVENT_KEY_DOWN:
                input->keys[e.key.scancode] = true;
            break;
            case SDL_EVENT_KEY_UP:
                input->keys[e.key.scancode] = false;
            break;

            case SDL_EVENT_QUIT:
                exit(0);
            break;
            case SDL_EVENT_MOUSE_MOTION:
                input->mouse_x = e.motion.x;
                input->mouse_y = e.motion.y;
            break;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if (e.button.button == SDL_BUTTON_LEFT) {
                    input->mouse_left = true;
                }
                if (e.button.button == SDL_BUTTON_RIGHT) {
                    input->mouse_right = true;
                }
            break;
            case SDL_EVENT_MOUSE_BUTTON_UP:
                if (e.button.button == SDL_BUTTON_LEFT)
                    input->mouse_left = false;
                if (e.button.button == SDL_BUTTON_RIGHT)
                    input->mouse_right = false;
                break;
        }
    }
}

/* if key pressed */
bool key_pressed(INP_Context *input, SDL_Scancode key) {
    return input->keys[key];
}
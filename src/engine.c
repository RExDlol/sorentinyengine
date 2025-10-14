#include "engine.h"

/* gameloop funcs */
void egn_init(EGN_Context *ctx) {
    SDL_Init(SDL_INIT_VIDEO);
    ctx->running = true;
}

void egn_update(EGN_Context *ctx) {
    input_update(&ctx->input);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                ctx->running = false;
                break;
        }
    }
}


/* setters */
void egn_setWindowTitle(EGN_Context *ctx, const char *title) {
    SDL_Window *window = ctx->gfx.window;

    SDL_SetWindowTitle(window, title);
}

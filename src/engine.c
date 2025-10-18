#include "engine.h"



/* starts some core things of the engine (required) */
void egn_init(EGN_Context *ctx) {
    SDL_Init(SDL_INIT_VIDEO);
    
    input_init(&ctx->input);

    ctx->running = true;
}
/* gameloop func */
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

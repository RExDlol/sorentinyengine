#ifndef ENGINE_H
#define ENGINE_H
#include <SDL3/SDL.h>

/* the three* forces of soren te (so rpg-y lol)*/
#include "input.h"
#include "gfx.h"
#include "tim.h"

/* add more later */
typedef struct {
    INP_Context input;
    GFX_WindowContext gfx;
    TIM_Context tim;
    // ecs context...

    int running;
    unsigned long frame;
    float delta_time;
} EGN_Context;

void egn_init(EGN_Context *ctx);

void egn_run();

void egn_update(EGN_Context *ctx);

void egn_setWindowTitle(EGN_Context *ctx, const char *title);

#endif
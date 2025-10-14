#ifndef TIM_H
#define TIM_H

#include <SDL3/SDL.h>

/* this keeps track of the time (good for the physics) */

typedef struct {
    float delta;
    Uint64 last_time;
    float fps;
} TIM_Context;

void tim_init(TIM_Context *tim);
void tim_update(TIM_Context *tim);

#endif

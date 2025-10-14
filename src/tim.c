#include "tim.h"

/* tim is an operator from brazil lol (time module in this proj ok) */

void tim_init(TIM_Context *tim) {
    tim->last_time = SDL_GetTicks64();
    tim->delta = 0.0f;
    tim->fps = 0.0f;
}

void tim_update(TIM_Context *tim) {
    Uint64 now = SDL_GetTicks();
    Uint64 diff = now - tim->last_time;

    /* ms to segs */
    tim->delta = diff / 1000.0f;

    /* ui ui tipo uma função recursiva */
    tim->last_time = now;

    if (tim->delta > 0) {
        tim->fps = 1.0f / tim->delta;
    }

}

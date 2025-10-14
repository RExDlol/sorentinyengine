#include <SDL3/SDL.h>
#include <stdio.h>
#include <math.h>

#include "engine.h"

int main() {
    EGN_Context egn;
    GFX_WindowContext gfx = egn.gfx;

    gfx.name = "soren tinyengine (TE)";
    gfx.width = 640 * 2;
    gfx.height = 360 * 2;
    gfx.flags = SDL_WINDOW_RESIZABLE;

    egn_init(&egn);
    gfx_init(&gfx);

    float time = 0.0f;

    SDL_Event e;

    while (egn.running) {
        egn_update(&egn);

        Color c = {
            0.f, 0.f, 0.f, 0.f
        };
        
        gfx_clear(&gfx, col_white);
        gfx_set_color(&gfx, col_neon_blue);

        if (egn.input.mouse_left || egn.input.mouse_right) {
            printf("ele clicou com o mouse em!! (%d, %d)\n", egn.input.mouse_x, egn.input.mouse_y);
        }

        gfx_draw_line(&gfx, 20, 20, 1000, 1000);
        gfx_present(&gfx);

        SDL_Delay(16);
    }

    gfx_quit(&gfx);
}

#include <stdio.h>
#include <math.h>

#include "engine.h"
char *font_dir = "fonts/BlexMonoNerdFont-Regular.ttf";
int main() {
    EGN_Context egn;
    GFX_WindowContext gfx = egn.gfx;

    gfx.name = "luiz femboy";
    gfx.width = 640 * 2;
    gfx.height = 360 * 2;
    gfx.flags = SDL_WINDOW_RESIZABLE;

    egn_init(&egn);
    gfx_init(&gfx);

    float time = 0.0f;

    SDL_Event e;

    while (egn.running) {
        egn_update(&egn);
        tim_update(&egn.tim);

        float dt = egn.tim.delta;
        
        gfx_clear(&gfx, col_soft_red);
        
        gfx_set_color(&gfx, col_white);
        
        gfx_draw_text(&gfx, "soren engine engin gn", font_dir, 32, egn.input.mouse_x, egn.input.mouse_y);
        gfx_draw_text(&gfx, "aperte W para mudar fonte", font_dir, 32, 0, 0);
        if (key_pressed(&egn.input, SDL_SCANCODE_W)) {
            font_dir = "fonts/FiraCode-Regular.ttf";
        }
        gfx_present(&gfx);

        SDL_Delay(16);
    }

    gfx_quit(&gfx);
}

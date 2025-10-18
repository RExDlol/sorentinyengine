#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

#include "gfx.h"

SDL_Window *gfx_init(GFX_WindowContext *ctx) {
    if (!TTF_Init()) {

        printf("-=-=-=-=-=-=-=-=-=-==-=-=-\nTE: Oh No! Error in SDL_TTF!! call soren pls in discord (yep, im not professional)\n-=-=-=-=-=-=-=-=-=-==-=-=-");
    }
    /* defining ctx's window & renderer*/
    SDL_Window *w = SDL_CreateWindow(ctx->name, ctx->width, ctx->height, ctx->flags);

    /* NULL cuz SDL will choose the best rendering driver */
    SDL_Renderer *r = SDL_CreateRenderer(w, NULL);

    ctx->window = w;
    ctx->renderer = r;

    return w;
}

void gfx_draw() {

}

/* color being an array of uint8 values corresponding to rgba */
void gfx_clear(GFX_WindowContext *ctx, Color c) {
    SDL_SetRenderDrawColor(ctx->renderer, c.r * 255., c.g * 255., c.b * 255., c.a * 255.);
    SDL_RenderClear(ctx->renderer);
}

void gfx_present(GFX_WindowContext *ctx) {
    SDL_RenderPresent(ctx->renderer);
}

void gfx_quit(GFX_WindowContext *ctx) {
    if (ctx->renderer) SDL_DestroyRenderer(ctx->renderer);
    if (ctx->window) SDL_DestroyWindow(ctx->window);
    TTF_Quit();
    SDL_Quit();
}

void gfx_set_color(GFX_WindowContext *ctx, Color c) {
    SDL_SetRenderDrawColor(ctx->renderer, c.r * 255., c.g * 255., c.b * 255., c.a * 255.);
}

void gfx_draw_line(GFX_WindowContext *ctx, float x1, float y1, float x2, float y2) {
    SDL_RenderLine(ctx->renderer, x1, y1, x2, y2);
}

void gfx_draw_text(GFX_WindowContext *ctx, const char *text, const char *font_dir, float font_size, float x, float y) {
    TTF_Font *font = TTF_OpenFont(font_dir, font_size);
    if (!font) {
        printf("TE | Error opening font: %s\n", SDL_GetError());
        return;
    }

    SDL_Color c = {255, 255, 255, 255};

    SDL_Surface *surf = TTF_RenderText_Solid(font, text, strlen(text), c);
    if (!surf) {
        printf("TE | Error rendering text: %s\n", SDL_GetError());
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ctx->renderer, surf);
    SDL_DestroySurface(surf);

    SDL_FRect dest = { x, y, (float)surf->w, (float)surf->h };

    SDL_RenderTexture(ctx->renderer, tex, NULL, &dest);
    SDL_DestroyTexture(tex);
    TTF_CloseFont(font);
}
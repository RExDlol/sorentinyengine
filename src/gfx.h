#ifndef GFX_H
#define GFX_H
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>
#include "util.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    int width, height;
    SDL_WindowFlags flags;
    const char *name;
} GFX_WindowContext;

SDL_Window *gfx_init(GFX_WindowContext *ctx);

void gfx_quit(GFX_WindowContext *ctx);

void gfx_clear(GFX_WindowContext *ctx, Color c);

void gfx_present(GFX_WindowContext *ctx);

void gfx_draw();

void gfx_draw_rect();

void gfx_draw_line(GFX_WindowContext *ctx, float x1, float y1, float x2, float y2);

void gfx_set_color(GFX_WindowContext *ctx, Color c);

void gfx_draw_text(GFX_WindowContext *ctx, const char *text, const char *font_dir, float font_size, float x, float y);

/* do after */
void gfx_load_texture();

void gfx_draw_texture();

void gfx_free_texture();

#endif
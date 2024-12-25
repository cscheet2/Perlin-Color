/*******************************************************************
 * 
 * @file colormap.c
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief Implementation of functions defined in `./colormap.h`
 * 
 *******************************************************************/

#include "./colormap.h"

void colorSurface(SDL_Surface* surface, uint8_t numOctaves, uint16_t width, uint16_t height) {
  uint32_t* pixels = (uint32_t*)surface->pixels;
	palette_t* palette = load_color_palette("light_blue");
  for (uint16_t y = 0; y < surface->h; y++) {
		for (uint16_t x = 0; x < surface->w; x++) {
			uint8_t index = fractalBrownianMotion((float)x, (float)y, numOctaves) * (palette->num_colors);
			pixels[y * surface->w + x] = SDL_MapRGB(surface->format, palette->colors[index].r, palette->colors[index].g, palette->colors[index].b);
		}
	}
  free_palette(palette);
}

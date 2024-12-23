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
	color_t* palette = load_color_palette("light_blue");
  for (uint16_t y = 0; y < surface->h; y++) {
		for (uint16_t x = 0; x < surface->w; x++) {
			uint8_t index = fractalBrownianMotion((float)x, (float)y, numOctaves) * (NUM_NUMERIAL_VALUES - 0.1);
			pixels[y * surface->w + x] = SDL_MapRGB(surface->format, palette[index].r, palette[index].g, palette[index].b);
      // pixels[y * surface->w + x] = (val > 0) ?
			// SDL_MapRGB(surface->format, 0, (uint8_t)(val*255), 0):
      // SDL_MapRGB(surface->format, 0, 0, (uint8_t)(val*255));
		}
	}
}

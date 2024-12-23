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
  for (uint16_t y = 0; y < surface->h; y++) {
		for (uint16_t x = 0; x < surface->w; x++) {
			float val = fractalBrownianMotion((float)x, (float)y, numOctaves);
      pixels[y * surface->w + x] = (val > 0) ?
			SDL_MapRGB(surface->format, (uint8_t)(val*255), 0, 0):
      SDL_MapRGB(surface->format, 0, 0, (uint8_t)(val*255));
		}
	}
}
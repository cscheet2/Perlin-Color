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
			u_int8_t r = fractalBrownianMotion((float)x, (float)y, numOctaves) * UINT8_MAX;
      u_int8_t g = fractalBrownianMotion((float)x, (float)y, numOctaves) * UINT8_MAX;
			u_int8_t b = fractalBrownianMotion((float)x, (float)y, numOctaves) * UINT8_MAX;
			pixels[y * surface->w + x] = SDL_MapRGB(surface->format, r, g, b);
		}
	}
}

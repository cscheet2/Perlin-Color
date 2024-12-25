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

void colorSurface(const char* color_name, SDL_Surface* surface, uint8_t numOctaves, uint16_t width, uint16_t height) {
  uint32_t* pixels = (uint32_t*)surface->pixels;
	palette_t* palette = load_color_palette(color_name);
  for (uint16_t y = 0; y < surface->h; y++) {
		for (uint16_t x = 0; x < surface->w; x++) {
			float noise = fabs(fractalBrownianMotion((float)x, (float)y, numOctaves - 1));
			uint8_t index = noise * (palette->num_colors);
			pixels[y * surface->w + x] = SDL_MapRGB(surface->format, palette->colors[index].r, palette->colors[index].g, palette->colors[index].b);
			// printf("%3d: (%3d,%3d) <- (%3d, %3d, %3d), %f\n", (int)index, (int)x, (int)y, (int)palette->colors[index].r&0xFF, (int)palette->colors[index].g&0xFF, (int)palette->colors[index].b&0xFF, noise);
		}
	}
  free_palette(palette);
}

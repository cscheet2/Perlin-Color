/*******************************************************************
 * 
 * @file main.c
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief Starting point for Perlin Color
 * 
 *******************************************************************/

#include <stdint.h>
#include <SDL2/SDL.h>

#include "./screentools.h"
#include "./noise.h"

#define APP_NAME   "Perlin Color"
#define APP_WIDTH  640
#define APP_HEIGHT 480

int main(void) {
	_reshufflePermutationArray();
	initSDL();
  SDL_Window*   window   = initWindow(APP_NAME, APP_WIDTH, APP_HEIGHT);
	SDL_Renderer* renderer = initRenderer(window);
	SDL_Surface*  surface  = initRGBSurface(APP_WIDTH, APP_HEIGHT);
	SDL_Event     event;

	uint32_t* pixels = (uint32_t*)surface->pixels;

	for (uint16_t y = 0; y < surface->h; y++) {
		for (uint16_t x = 0; x < surface->w; x++) {
			float val = fractalBrownianMotion((float)x, (float)y, 2U);
			pixels[y * surface->w + x] = SDL_MapRGB(surface->format, (int)(val*255), (int)(val*255), (int)(val*255));
		}
	}
	
	renderSurface(renderer, surface);

	while (42) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) { break; }
	}

	SDL_FreeSurface(surface);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
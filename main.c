/*******************************************************************
 * 
 * @file main.c
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief Starting point for Perlin Color
 * 
 ******************************************************************/

#include <stdint.h>
#include <SDL2/SDL.h>

#include "./screentools.h"
#include "./noise.h"
#include "./colormap.h"

#define APP_NAME   "Perlin Color"
#define APP_WIDTH  640
#define APP_HEIGHT 480

int main(void) {
	reshufflePermutationArray();
	initSDL();
  SDL_Window*   window   = initWindow(APP_NAME, APP_WIDTH, APP_HEIGHT);
	SDL_Renderer* renderer = initRenderer(window);
	SDL_Surface*  surface  = initRGBSurface(APP_WIDTH, APP_HEIGHT);
	SDL_Event     event;

	colorSurface(surface, 3U, APP_WIDTH, APP_HEIGHT);
	renderSurface(renderer, surface);

	while (":3") {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) { break; }
		SDL_Delay(16);  // 60 fps
	}

	SDL_FreeSurface(surface);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
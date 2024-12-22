#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./screentools.h"

#define APP_NAME   "Perlin Color"
#define APP_WIDTH  640
#define APP_HEIGHT 480

int main(void) {
	initSDL();
  SDL_Window* window = initWindow(APP_NAME, APP_WIDTH, APP_HEIGHT);
	SDL_Renderer* renderer = initRenderer(window);
	SDL_Surface* surface = initRGBSurface(APP_WIDTH, APP_HEIGHT);

	Uint32* pixels = (Uint32*)surface->pixels;
	srand(time(NULL));

	for (int y = 0; y < surface->h; y++) {
		for (int x = 0; x < surface->w; x++) {
			pixels[y * surface->w + x] = SDL_MapRGB(surface->format, rand()%256, rand()%256, rand()%256);
		}
	}
	SDL_Texture* texture = initTextureFromSurface(renderer, surface);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

  SDL_Delay(5000); // Wait for 2 seconds
	SDL_FreeSurface(surface);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
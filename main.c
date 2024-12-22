#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH  640
#define HEIGHT 480

int main() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }
  SDL_Window* window = SDL_CreateWindow("Perlin Color", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if (window == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    return 1;
  }
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
  	printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
  	return 1;
	}
	// SDL_Surface *surface = SDL_GetWindowSurface(window);
	SDL_Surface *surface = SDL_CreateRGBSurface(0, HEIGHT, WIDTH, 32, 0, 0, 0, 0);
	if (surface == NULL) {
    printf("SDL_GetWindowSurface Error: %s\n", SDL_GetError());
    return 1;
  }

	Uint32* pixels = (Uint32*)surface->pixels;
	srand(time(NULL));

	for (int y = 0; y < surface->h; y++) {
		for (int x = 0; x < surface->w; x++) {
			pixels[y * surface->w + x] = SDL_MapRGB(surface->format, rand()%256, rand()%256, rand()%256);
		}
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
    printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
	}
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);


  SDL_Delay(5000); // Wait for 2 seconds
	SDL_FreeSurface(surface);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
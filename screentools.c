/*******************************************************************
 * 
 * @file screentools.c
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief Implementation of functions defined in `./screentools.h`
 * 
 *******************************************************************/

#include "./screentools.h"

void initSDL(void) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr ,"SDL_Init Error: %s\n", SDL_GetError());
    exit(1);
  }
}

SDL_Window* initWindow(char* application_name, int screen_width, int screen_height) {
  SDL_Window* window = SDL_CreateWindow("Perlin Color", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, 0);
  if (window == NULL) {
    fprintf(stderr ,"SDL_CreateWindow Error: %s\n", SDL_GetError());
    exit(1);
  }
  return window;
}

SDL_Renderer* initRenderer(SDL_Window* window) {
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
  	fprintf(stderr ,"SDL_CreateRenderer Error: %s\n", SDL_GetError());
  	exit(1);
	}
  return renderer;
}

SDL_Surface* initRGBSurface(int surface_width, int surface_height) {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, surface_width, surface_height, 32, 0, 0, 0, 0);
	if (surface == NULL) {
    fprintf(stderr ,"SDL_GetWindowSurface Error: %s\n", SDL_GetError());
    exit(1);
  }
  return surface;
}

SDL_Texture* initTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface) {
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
    fprintf(stderr ,"SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    exit(1);
	}
  return texture;
}


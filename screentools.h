/*******************************************************************
 * 
 * @file screentools.h
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief A collection of functions that help with initializing 
 *        various SDL screen tools with proper error handling
 * 
 *******************************************************************/

#ifndef SCREENTOOLS_H
#define SCREENTOOLS_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

/**
 * Initialize SDL and provide error handling
 */
void initSDL(void);

/**
 * Initialize an SDL window and provide error handling
 * 
 * @param application_name (char*)
 * @param screen_width (int)
 * @param screen_height (int)
 * @return (SDL_Window*)
 */
SDL_Window* initWindow(char* application_name, int screen_width, int screen_height);

/**
 * Initialize a renderer and provide error handling
 * 
 * @param window (SDL_Window*)
 * @return (SDL_Renderer*)
 */
SDL_Renderer* initRenderer(SDL_Window* window);

/**
 * Initialize and RGB surface and provide error handling
 * 
 * @param surface_width (int)
 * @param surface_height (int)
 * @return (SDL_Surface*)
 */
SDL_Surface* initRGBSurface(int surface_width, int surface_height);

/**
 * Initialize a texture from a surface and provide error handling
 * 
 * @param renderer (SDL_Renderer*)
 * @param surface (SDL_Surface*)
 * @return (SDL_Texture*)
 */
SDL_Texture* initTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);

#endif //SCREENTOOLS_H
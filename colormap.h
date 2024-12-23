/*******************************************************************
 * 
 * @file colormap.h
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief A collection of functions to map noise values to
 *        RGB values on a SDL_Surface
 * 
 *******************************************************************/

#ifndef COLORMAP_H
#define COLORMAP_H

#include <stdint.h>
#include <SDL2/SDL.h>

#include "./noise.h"
#include "./load_palettes.h"

/**
 * Given a surface, color that surface with random RGB Values
 * 
 * @param surface (SDL_Surface*) surface to color
 * @param numOctaves (uint8_t) number of octaves
 * @param width (uint16_t) width of surface
 * @param height (uint16_t) height of surface
 */
void colorSurface(SDL_Surface* surface, uint8_t numOctaves, uint16_t width, uint16_t height);

#endif //COLORMAP_H

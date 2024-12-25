/*******************************************************************
 * 
 * @file load_palettes.h
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief A collection of functions that load colors from the 
 *        `color_palettes.json` file.
 * 
 * Color Pallets from from the following site, but in RGB.
 *   - https://rgbacolorpicker.com/hex-to-rgba
 * 
 *******************************************************************/

#ifndef LOAD_PALETTES_H
#define LOAD_PALETTES_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

/**
 * Path from build directory
 */
#define COLOR_JSON_PATH "./../color_palettes.txt"

#define MAX_PALETTE_NAME_LEN 50


/**
 * Represent a color's RGB values.
 */
typedef struct color_t {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} color_t;

/**
 * Represent a color palette.
 */
typedef struct palette_t {
  char* palette_name;
  color_t* colors;
  uint8_t num_colors;
} palette_t;

/**
 * Allocate memory and initialize a palette_t.
 * Colors are initalized to NULL, add a color
 * with the `append_palette_color` function.
 * Return NULL if name is NULL.
 * 
 * @param palette_name (const char*)
 * @return (palette_t*)
 */
palette_t* create_palette(const char* palette_name);

/**
 * Append a color to the palette colors array,
 * throw error if unable to add color
 * 
 * @param palette (palette*)
 * @param red (uint8_t)
 * @param green (uint8_t)
 * @param blue (uint8_t)
 */
void append_palette_color(palette_t* palette, uint8_t red, uint8_t green, uint8_t blue);

/**
 * Free a palette and the shallow copy
 * array of the collors array
 * 
 * @param palette (palette_t*)
 */
void free_palette(palette_t* palette);

/**
 * Throws an error with the following message.
 * 
 * @param error_message (const char*)
 */
void _throw_error(const char* error_message);

/**
 * If endline character exists at the end of the string
 * replace it with the null terminator.
 * 
 * @param string (char*)
 */
void _remove_endl(char* string);

/**
 * Loads inputted color form the `color_palette` JSON.
 * The resulting array will be in ascending order of 
 * numeric values. User must free colors.
 * Throw error if color cannot be parsed.
 * 
 * @param color (const char*)
 * @returns (palette_t*)
 */
palette_t* load_color_palette(const char* color_name);

#endif //LOAD_PALETTES_H
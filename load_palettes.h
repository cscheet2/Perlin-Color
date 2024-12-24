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
#define COLOR_JSON_PATH "./../color_palettes.json"

#define NUM_NUMERIAL_VALUES 10
const char* NUMERICAL_COLOR_VALUES[NUM_NUMERIAL_VALUES] = 
{ 
  "50", "100", "200", "300", "400", "500", "600", "700", "800", "900" 
};

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
 * Allocate memory and initialize a color_t.
 * 
 * @param red (uint8_t)
 * @param green (uint8_t)
 * @param blue (uint8_t)
 * @return (color_t*)
 */
color_t* init_color(uint8_t red, uint8_t green, uint8_t blue);

/**
 * Free a color_t.
 * 
 * @param color (color_t)
 */
void free_color(color_t* color);

/**
 * Allocate memory and initialize a palette_t.
 * Return NULL if name and colors are NULL.
 * 
 * @param name (const char*)
 * @param colors (color_t*) list of colors
 * @param num_colors (uint8_t) length of colors list
 */
palette_t* init_palette(const char* name, color_t* colors, uint8_t num_colors);

/**
 * Free a palette.
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
 * Get the RGB value in the string.
 * 
 * @param string (char*)
 * @returns (uint8_t) RGB Value
 */
uint8_t _get_RGB_value(const char* string);

/**
 * Loads inputted color form the `color_palette` JSON.
 * The resulting array will be in ascending order of 
 * numeric values. User must free colors.
 * Throw error if color cannot be parsed.
 * 
 * @param color (const char*)
 * @returns (color_t*) color array
 */
palette_t* load_color_palette(const char* color_name);

#endif //LOAD_PALETTES_H
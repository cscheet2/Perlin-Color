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
color_t* load_color_palette(const char* color_name);

#endif //LOAD_PALETTES_H
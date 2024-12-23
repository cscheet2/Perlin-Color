/*******************************************************************
 * 
 * @file load_palettes.c
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief Implementation of functions defined in `./load_palettes.h`
 * 
 *******************************************************************/

#include "./load_palettes.h"


color_t* init_color(uint8_t red, uint8_t green, uint8_t blue) {
  color_t* color = (color_t*) malloc(sizeof(color_t) * 1);
  color->r = red;
  color->g = green;
  color->b = blue;
  return color;
}

void free_color(color_t* color) {
  if (color != NULL) { free(color); }
}

palette_t* init_palette(const char* name, color_t* colors, uint8_t num_colors) {
  if (name == NULL || colors == NULL) { return NULL; }
  palette_t* palette = (palette_t*) malloc(sizeof(palette_t) * 1);
  palette->palette_name = (char*) malloc(sizeof(char) * strlen(name) + 1);

  strncpy(palette->palette_name, name, 255);
}

void free_palette(palette_t* palette) {

}

void _throw_error(const char* error_message) {
  fprintf(stderr, "%s\n", error_message);
  exit(1);
}

void _remove_endl(char* string) {
  if (string[strlen(string)-1] == '\0') { string[strlen(string)-1] = '\0'; }
}

uint8_t _get_RGB_value(const char* string) {
  char num[4] = { 0, 0, 0, 0 };
  for (uint8_t i = 0; i < strlen(string); i++) {
    if (isdigit(string[i])) {
      num[strlen(num)] = string[i];
    }
  }
  return (uint8_t)atoi(num);
}

palette_t* load_color_palette(const char* color_name) {
  FILE *json = fopen(COLOR_JSON_PATH, "r");
  if (json == NULL) { _throw_error("Failed to load color palettes ERROR"); }

  const uint8_t BUFFER_SIZE = UINT8_MAX;
  char buffer[BUFFER_SIZE];

  uint8_t found = 0;
  char *line = fgets(buffer, BUFFER_SIZE, json); 
  while (line != NULL) {
    if (strstr(buffer, color_name) != NULL) { found = 1; break; }
    line = fgets(buffer, BUFFER_SIZE, json);
  }

  if (!found) { _throw_error("Failed to find color in palette ERROR"); }

  color_t* colors = (color_t*)malloc(sizeof(color_t) * NUM_NUMERIAL_VALUES);
  uint8_t num_added = 0;
  uint8_t is_error = 0;
  while (!is_error && line != NULL && num_added < NUM_NUMERIAL_VALUES) {
    line = fgets(buffer, BUFFER_SIZE, json);
         if (strstr(buffer, "r") != NULL) { colors[num_added].r = _get_RGB_value(buffer);              }
    else if (strstr(buffer, "g") != NULL) { colors[num_added].g = _get_RGB_value(buffer);              }
    else if (strstr(buffer ,"b") != NULL) { colors[num_added].b = _get_RGB_value(buffer); num_added++; }
  }

  if (num_added != NUM_NUMERIAL_VALUES) { _throw_error("Found but failed to load color in palette ERROR"); }

  fclose(json);

  // return colors;
}

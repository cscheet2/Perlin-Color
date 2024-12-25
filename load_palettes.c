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

palette_t* create_palette(const char* palette_name) {
  if (palette_name == NULL) { return NULL; }
  palette_t* palette = (palette_t*) malloc(sizeof(palette_t) * 1);
  palette->palette_name = (char*) malloc(sizeof(char) * MAX_PALETTE_NAME_LEN);

  strncpy(palette->palette_name, palette_name, MAX_PALETTE_NAME_LEN);
  palette->colors = NULL;
  palette->num_colors = 0;

  return palette;
}

void append_palette_color(palette_t* palette, uint8_t red, uint8_t green, uint8_t blue) {
  if (palette == NULL) { return; }
  color_t* new_color_ptr = (color_t*) realloc(palette->colors, sizeof(color_t) * 1);
  if (new_color_ptr == NULL) { _throw_error("Failed to append color ERROR"); }
  palette->colors[palette->num_colors] = (color_t) { red, green, blue };
  palette->num_colors++;
}

void free_palette(palette_t* palette) {
  if (palette == NULL) { return; }
  free(palette->palette_name);
  free(palette->colors);
  free(palette);
}

void _throw_error(const char* error_message) {
  fprintf(stderr, "%s\n", error_message);
  exit(1);
}

void _remove_endl(char* string) {
  if (string[strlen(string)-1] == '\0') { string[strlen(string)-1] = '\0'; }
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

  palette_t* palette = create_palette(color_name);
  while(line != NULL && buffer[0] != '\n') {
    printf(":3");
    const uint8_t r = (uint8_t)atoi(strtok(buffer, " "));
    const uint8_t g = (uint8_t)atoi(strtok(NULL,   " "));
    const uint8_t b = (uint8_t)atoi(strtok(NULL,   " "));
    append_palette_color(palette, r, g, b);
  }

  fclose(json);

  return palette;
}

  // FILE *json = fopen(COLOR_JSON_PATH, "r");
  // if (json == NULL) { _throw_error("Failed to load color palettes ERROR"); }

  // const uint8_t BUFFER_SIZE = UINT8_MAX;
  // char buffer[BUFFER_SIZE];

  // uint8_t found = 0;
  // char *line = fgets(buffer, BUFFER_SIZE, json); 
  // while (line != NULL) {
  //   if (strstr(buffer, color_name) != NULL) { found = 1; break; }
  //   line = fgets(buffer, BUFFER_SIZE, json);
  // }

  // if (!found) { _throw_error("Failed to find color in palette ERROR"); }

  // color_t* colors = (color_t*)malloc(sizeof(color_t) * NUM_NUMERIAL_VALUES);
  // uint8_t num_added = 0;
  // uint8_t is_error = 0;
  // while (!is_error && line != NULL && num_added < NUM_NUMERIAL_VALUES) {
  //   line = fgets(buffer, BUFFER_SIZE, json);
  //        if (strstr(buffer, "r") != NULL) { colors[num_added].r = _get_RGB_value(buffer);              }
  //   else if (strstr(buffer, "g") != NULL) { colors[num_added].g = _get_RGB_value(buffer);              }
  //   else if (strstr(buffer ,"b") != NULL) { colors[num_added].b = _get_RGB_value(buffer); num_added++; }
  // }

  // if (num_added != NUM_NUMERIAL_VALUES) { _throw_error("Found but failed to load color in palette ERROR"); }

  // fclose(json);

  // return colors;

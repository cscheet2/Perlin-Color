/*******************************************************************
 * 
 * @file colormap.c
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief Implementation of functions defined in `./colormap.h`
 * 
 *******************************************************************/

#include "./colormap.h"

static long long unsigned* palette_log = NULL;
static inline void init_log(const uint8_t log_length);
static inline void update_log(const uint8_t index);
static inline void free_log();
static inline void print_log_index_precentages(const palette_t* palette);

void colorSurface(const char* color_name, SDL_Surface* surface, uint8_t numOctaves, uint16_t width, uint16_t height) {
	reshufflePermutationArray();
  uint32_t* pixels = (uint32_t*)surface->pixels;
	palette_t* palette = load_color_palette(color_name);
  init_log(palette->num_colors);
	const float scale = 0.01F;
  for (uint16_t y = 0; y < surface->h; y++) {
		for (uint16_t x = 0; x < surface->w; x++) {
			float noise = ((fractalBrownianMotion2D((float)x * scale, (float)y * scale, numOctaves)) + 1.0F) / 2.0F;
			uint8_t index = (uint8_t)(noise * (palette->num_colors));
			pixels[y * surface->w + x] = SDL_MapRGBA(surface->format, palette->colors[index].r, palette->colors[index].g, palette->colors[index].b, 255);
      update_log(index);
		}
	}
  print_log_index_precentages(palette);
  free_palette(palette);
  free_log();
}

static inline void init_log(const uint8_t log_length) {
  palette_log = (long long unsigned*) calloc(log_length, sizeof(long long unsigned));
}
static inline void update_log(const uint8_t index) {
  palette_log[index] += 1;
}
static inline void free_log() {
  free(palette_log);
}
static inline void print_log_index_precentages(const palette_t* palette) {
  long double sum = 0;
  for (uint8_t index = 0; index < palette->num_colors; index++) { sum += palette_log[index]; }

  fprintf(stderr, "|-------|--------|---------|-----------------|\n");
  fprintf(stderr, "| index | amount | precent | RGB color value |\n");
  fprintf(stderr, "|-------|--------|---------|-----------------|\n");
  
  for (uint8_t index = 0; index < palette->num_colors; index++) {
    fprintf(stderr, "| %5d ", (int)index);
    fprintf(stderr, "| %6llu ", palette_log[index]);
    fprintf(stderr, "| %6.02Lf%% ", ((long double)palette_log[index] / sum) * 100);
    fprintf(stderr, "| (%3u, %3u, %3u) ", (unsigned int) palette->colors[index].r, (unsigned int) palette->colors[index].g, (unsigned int) palette->colors[index].b);
    fprintf(stderr, "|\n");
  }
  fprintf(stderr, "|-------|--------|---------|-----------------|\n");
}

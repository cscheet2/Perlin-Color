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

void colorSurface(const char* color_name, SDL_Surface* surface, uint8_t numOctaves, uint16_t width, uint16_t height) {
	reshufflePermutationArray();
	long long unsigned l0 = 0, l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0;
  uint32_t* pixels = (uint32_t*)surface->pixels;
	palette_t* palette = load_color_palette(color_name);
	float scale = 0.01F;
  for (uint16_t y = 0; y < surface->h; y++) {
		for (uint16_t x = 0; x < surface->w; x++) {
			float noise = ((fractalBrownianMotion2D((float)x * scale, (float)y * scale, numOctaves)) + 1.0F) / 2.0F;
			uint8_t index = (uint8_t)(noise * (palette->num_colors));
			pixels[y * surface->w + x] = SDL_MapRGBA(surface->format, palette->colors[index].r, palette->colors[index].g, palette->colors[index].b, 255);	     
			     if (index == 0) { l0++; }
			else if (index == 1) { l1++; }
			else if (index == 2) { l2++; }
			else if (index == 3) { l3++; }
			else if (index == 4) { l4++; }
			else if (index == 5) { l5++; }
			else if (index == 6) { l6++; }
			else if (index == 7) { l7++; }
			else if (index == 8) { l8++; }
			else if (index == 9) { l9++; }
			// printf("%3d: (%3d,%3d) <- (%3d, %3d, %3d), %f\n", (int)index, (int)x, (int)y, (int)palette->colors[index].r&0xFF, (int)palette->colors[index].g&0xFF, (int)palette->colors[index].b&0xFF, noise);
		}
	}
	long double sum = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9;
	long double a0 = ((long double)l0/sum)*100, a1 = ((long double)l1/sum)*100, a2 = ((long double)l2/sum)*100, a3 = ((long double)l3/sum)*100, a4 = ((long double)l4/sum)*100;
	long double a5 = ((long double)l5/sum)*100, a6 = ((long double)l6/sum)*100, a7 = ((long double)l7/sum)*100, a8 = ((long double)l8/sum)*100, a9 = ((long double)l9/sum)*100;
	printf("Total: %llu\n", (long long unsigned)sum);
	printf("l0 = %5llu, %3.02Lf%%\nl1 = %5llu, %3.02Lf%%\nl2 = %5llu, %3.02Lf%%\nl3 = %5llu, %3.02Lf%%\nl4 = %5llu, %3.02Lf%%\n", 
					l0, a0, l1, a1, l2, a2, l3, a3, l4, a4);
	printf("l5 = %5llu, %3.02Lf%%\nl6 = %5llu, %3.02Lf%%\nl7 = %5llu, %3.02Lf%%\nl8 = %5llu, %3.02Lf%%\nl9 = %5llu, %3.02Lf%%\n", 
					l5, a5, l6, a6, l7, a7, l8, a8, l9, a9);
  free_palette(palette);
}


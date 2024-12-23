/*******************************************************************
 * 
 * @file noise.h
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief A collection of functions to make 2D perlin noise
 * 
 * The follow site was used to learn perlin noise:
 *   - https://rtouti.github.io/graphics/perlin-noise-algorithm
 * 
 *******************************************************************/

#ifndef NOISE_H
#define NOISE_H

#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

/**
 * Struct to represent a 2D vector.
 */
typedef struct vector_t {
  float x;
  float y;
} vector_t;

/**
 * Apply the fade function `f(t)=6t^5-15t^t-10t^3` to the input `t`.
 * 
 * @param t (float) fade input
 * @return (float) fade function output
 */
float _fade(float t);

/**
 * Apply the dot product to the following two vectors.
 * 
 * @param v1 (vector_t) vector 1
 * @param v2 (vector_t) vector 2
 * @return (float) dot product of vectors
 */
float _dot(vector_t v1, vector_t v2);

/**
 * Apply linear interpolation to the inputs.
 * 
 * @param t (float) line
 * @param p1 (float) point 1
 * @param p2 (float) point 2
 * @return (float) linear interpolation of points
 */
float _lerp(float t, float p1, float p2);

/**
 * Given a index for a permutation table, access that,
 * return constant vector.
 * 
 * @param permutation (uint8_t) permutation from table
 * @return (vector) constant unit vector
 */
vector_t _getConstantVector(uint8_t permutation);

/**
 * Reshuffles the `_permutations` array.
 */
void _reshufflePermutationArray(void);

/**
 * Return the 2D noise value of the current coords.
 * 
 * @param x (float) x-coord * frequency
 * @param y (float) y-coord * frequency
 * @return (float) 2D noise value
 */
float noise2D(float x, float y);

/**
 * Return the fractal browian motion noise value of 
 * the current (x,y) coordinates when given the number
 * of octaves. More detail requrires more octaves.
 * 
 * @param x (float) x-coord
 * @param y (float) y-coord
 * @param numOctaves (uint8_t) number of octaves
 */
float fractalBrownianMotion(float x, float y, uint8_t numOctaves);

/**
 * Length of `_permutations` array.
 */
#define NUM_PERMUTATIONS 256

/**
 * Ken Perlins original perlin noise permutations.
 * Array with shuffed values from 0-255.
 */
uint8_t _permutations[NUM_PERMUTATIONS] = 
  { 
    151, 160, 137,  91,  90,  15, 131,  13, 201,  95,  96,  53, 194, 233,   7, 225,
    140,  36, 103,  30,  69, 142,   8,  99,  37, 240,  21,  10,  23, 190,   6, 148,
    247, 120, 234,  75,   0,  26, 197,  62,  94, 252, 219, 203, 117,  35,  11,  32,
     57, 177,  33,  88, 237, 149,  56,  87, 174,  20, 125, 136, 171, 168,  68, 175,
     74, 165,  71, 134, 139,  48,  27, 166,  77, 146, 158, 231,  83, 111, 229, 122,
     60, 211, 133, 230, 220, 105,  92,  41,  55,  46, 245,  40, 244, 102, 143,  54,
     65,  25,  63, 161,   1, 216,  80,  73, 209,  76, 132, 187, 208,  89,  18, 169,
    200, 196, 135, 130, 116, 188, 159,  86, 164, 100, 109, 198, 173, 186,   3,  64,
     52, 217, 226, 250, 124, 123,   5, 202,  38, 147, 118, 126, 255,  82,  85, 212,
    207, 206,  59, 227,  47,  16,  58,  17, 182, 189,  28,  42, 223, 183, 170, 213,
    119, 248, 152,   2,  44, 154, 163,  70, 221, 153, 101, 155, 167,  43, 172,   9,
    129,  22,  39, 253,  19,  98, 108, 110,  79, 113, 224, 232, 178, 185, 112, 104,
    218, 246,  97, 228, 251,  34, 242, 193, 238, 210, 144,  12, 191, 179, 162, 241,
     81,  51, 145, 235, 249,  14, 239, 107,  49, 192, 214,  31, 181, 199, 106, 157,
    184,  84, 204, 176, 115, 121,  50,  45, 127,   4, 150, 254, 138, 236, 205,  93,
     22, 114,  67,  29,  24,  72, 243, 141, 128, 195,  78,  66, 215,  61, 156, 180 
  };

#endif //NOISE_H
/*******************************************************************
 * 
 * @file noise.c
 * 
 * @author Raegan (Cameron) Scheet
 * 
 * @brief Implementation of functions defined in `./noise.h`
 * 
 * The follow site was used to learn perlin noise:
 *   - https://rtouti.github.io/graphics/perlin-noise-algorithm
 * 
 *******************************************************************/

#include "./noise.h"

float _fade(float t) {
  return ((6*t - 15)*t + 10)*t*t*t;
}

float _dot(vector_t v1, vector_t v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

float _lerp(float t, float p1, float p2) {
  return p1 + t * (p2 - p1);
}

vector_t _getConstantVector(uint8_t permutation) {
  switch (permutation & 0b11) {
    case 0:  return (vector_t) {  1.0F,  1.0F };
    case 1:  return (vector_t) { -1.0F,  1.0F };
    case 2:  return (vector_t) { -1.0F, -1.0F };
    default: return (vector_t) {  1.0F, -1.0F };
  }
}

void reshufflePermutationArray(void) {
  srand(time(NULL));
  for (uint8_t i = NUM_PERMUTATIONS - 1; i > 0; i--) {
    const uint8_t j = (uint8_t) rand();
    const uint8_t temp = _permutations[i];
    _permutations[i] = _permutations[j];
    _permutations[j] = temp;
  }
}

float noise2D(float x, float y) {
  
  const uint8_t X = (uint8_t)x;
  const uint8_t Y = (uint8_t)y;
  
  const float xf = x - floorf(x);
  const float yf = y - floorf(y);

  const vector_t top_right = { xf - 1.0F, yf - 1.0F };
  const vector_t top_left  = { xf       , yf - 1.0F };
  const vector_t bot_right = { xf - 1.0F, yf        };
  const vector_t bot_left  = { xf       , yf        };

  const uint8_t val_top_right = _permutations[_permutations[X+1U]+Y+1U];
  const uint8_t val_top_left  = _permutations[_permutations[X   ]+Y+1U];
  const uint8_t val_bot_right = _permutations[_permutations[X+1U]+Y   ];
  const uint8_t val_bot_left  = _permutations[_permutations[X   ]+Y   ];

  const float dot_top_right = _dot(top_right, _getConstantVector(val_top_right));
  const float dot_top_left  = _dot(top_left,  _getConstantVector(val_top_left ));
  const float dot_bot_right = _dot(bot_right, _getConstantVector(val_bot_right));
  const float dot_bot_left  = _dot(bot_left,  _getConstantVector(val_bot_left ));

  const float u = _fade(xf);
  const float v = _fade(yf);

  return _lerp(u, _lerp(v, dot_bot_left, dot_top_left), _lerp(v, dot_bot_right, dot_top_right));
}

float fractalBrownianMotion(float x, float y, uint8_t numOctaves) {
  float result = 0.0F;
  float amplitude = 1.0F;
  float frequency = 0.005F;
  for (int octave = 0; octave < numOctaves; octave++) {
    result += amplitude * noise2D(x * frequency, y * frequency);
    amplitude *= 0.5F;
    frequency *= 2.0F;
  }
  return result;
}

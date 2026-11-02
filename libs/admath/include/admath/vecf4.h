#pragma once

typedef struct {
  float x, y, z, w;
} vecf4;

vecf4 add_vecf4(unsigned int amount, vecf4 vectors[]);
vecf4 subtract_vecf4(unsigned int amount, vecf4 vectors[]);
vecf4 multiply_vecf4(unsigned int amount, vecf4 vectors[]);
vecf4 divide_vec4f(unsigned int amount, vecf4 vectors[]);

vecf4 normalize_vec4f(vecf4 vector);

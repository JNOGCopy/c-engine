#pragma once

typedef struct {
  float x, y, z;
} vecf3;

vecf3 add_vecf3(unsigned int amount, vecf3 vectors[]);
vecf3 subtract_vecf3(unsigned int amount, vecf3 vectors[]);
vecf3 cross_product_vecf3(unsigned int amount, vecf3 vectors[]);

vecf3 normalize_vec3f(vecf3 vector);

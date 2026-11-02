#include "../include/admath/vecf2.h"
#include <math.h>
#include <threads.h>

inline vecf2 add_vecf2(unsigned int amount, vecf2 vectors[]) {
  vecf2 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x += vectors[i].x;
    temp.y += vectors[i].y;
  }
  return temp;
}
inline vecf2 subtract_vecf2(unsigned int amount, vecf2 vectors[]) {
  vecf2 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x -= vectors[i].x;
    temp.y -= vectors[i].y;
  }
  return temp;
}
inline float cross_product_vecf2(unsigned int amount, vecf2 vectors[]) {
  vecf2 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x *= vectors[i].x;
    temp.y *= vectors[i].y;
  }
  return temp.x + temp.y;
}

inline float get_length_vecf2(vecf2 vector) {
  return sqrt(powf(vector.x, 2) + powf(vector.y, 2));
}

inline vecf2 normalize_vecf2(vecf2 vector) {
  float length = get_length_vecf2(vector);
  vecf2 vec = {vector.x / length, vector.y / length};

  return vec;
}

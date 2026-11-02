#include "../include/admath/vecf3.h"
#include <math.h>
#include <threads.h>

inline vecf3 add_vecf3(unsigned int amount, vecf3 vectors[]) {
  vecf3 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x += vectors[i].x;
    temp.y += vectors[i].y;
    temp.z += vectors[i].z;
  }
  return temp;
}
inline vecf3 subtract_vecf3(unsigned int amount, vecf3 vectors[]) {
  vecf3 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x -= vectors[i].x;
    temp.y -= vectors[i].y;
    temp.z -= vectors[i].z;
  }
  return temp;
}
inline vecf3 cross_product_vecf3(unsigned int amount, vecf3 vectors[]) {
  vecf3 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x = temp.y * vectors[i].z + temp.z * vectors[i].y;
    temp.y = temp.z * vectors[i].x + temp.x * vectors[i].z;
    temp.z = temp.x * vectors[i].y + temp.y * vectors[i].x;
  }
  return temp;
}

inline float get_length_vecf3(vecf3 vector) {
  return sqrt(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
}

inline vecf3 normalize_vecf3(vecf3 vector) {
  float length = get_length_vecf3(vector);
  vecf3 vec = {vector.x / length, vector.y / length, vector.z / length};

  return vec;
}

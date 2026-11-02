#include "../include/admath/vecf4.h"
#include <math.h>
#include <threads.h>

inline vecf4 add_vecf4(unsigned int amount, vecf4 vectors[]) {
  vecf4 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x += vectors[i].x;
    temp.y += vectors[i].y;
    temp.z += vectors[i].z;
    temp.w += vectors[i].w;
  }
  return temp;
}
inline vecf4 subtract_vecf4(unsigned int amount, vecf4 vectors[]) {
  vecf4 temp = vectors[0];
  for (int i = 1; i < amount; i++) {
    temp.x -= vectors[i].x;
    temp.y -= vectors[i].y;
    temp.z -= vectors[i].z;
    temp.w -= vectors[i].w;
  }
  return temp;
}

inline float get_length_vecf4(vecf4 vector) {
  return sqrtf(powf(vector.x, 2) + powf(vector.y, 2) +
               powf(vector.z, 2) * powf(vector.w, 2));
}

inline vecf4 normalize_vecf4(vecf4 vector) {
  float length = get_length_vecf4(vector);
  vecf4 vec = {vector.x / length, vector.y / length, vector.z / length,
               vector.w / length};

  return vec;
}

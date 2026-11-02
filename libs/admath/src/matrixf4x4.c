#include "../include/admath/matrixf4x4.h"

matrixf4x4 add_matrixf4x4(unsigned int amount, matrixf4x4 matrices[]) {
  matrixf4x4 temp = matrices[0];
  for (int i = 1; i < amount; i++) {
    matrixf4x4 current_matrix = matrices[i];
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        temp.matrix[y][x] += current_matrix.matrix[y][x];
      }
    }
  }
  return temp;
}
matrixf4x4 subtract_matrixf4x4(unsigned int amount, matrixf4x4 matrices[]) {
  matrixf4x4 temp = matrices[0];
  for (int i = 1; i < amount; i++) {
    matrixf4x4 current_matrix = matrices[i];
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        temp.matrix[y][x] -= current_matrix.matrix[y][x];
      }
    }
  }
  return temp;
}
matrixf4x4 multiply_matrixf4x4(unsigned int amount, matrixf4x4 matrices[]) {
  matrixf4x4 temp = matrices[0];
  for (int i = 0; i < amount; i++) {
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        float current = 0.0f;
        for (int z = 0; z < 4; z++) {
          current += temp.matrix[y][z] * temp.matrix[z][x];
        }
        temp.matrix[y][x] = current;
      }
    }
  }
  return temp;
}

matrixf4x4 divide_matrixf4x4(unsigned int amount, matrixf4x4 matrices[]) {
  matrixf4x4 temp = matrices[0];
  for (int i = 0; i < amount; i++) {
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        float current = 0.0f;
        for (int z = 0; z < 4; z++) {
          current += temp.matrix[y][z] / temp.matrix[z][x];
        }
        temp.matrix[y][x] = current;
      }
    }
  }
  return temp;
}

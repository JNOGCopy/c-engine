#pragma once

typedef struct {
  float matrix[4][4];
} matrixf4x4;

matrixf4x4 add_matrixf4x4(unsigned int amount, matrixf4x4 vectors[]);
matrixf4x4 subtract_matrixf4x4(unsigned int amount, matrixf4x4 vectors[]);
matrixf4x4 multiply_matrixf4x4(unsigned int amount, matrixf4x4 vectors[]);
matrixf4x4 divide_matrixf4x4(unsigned int amount, matrixf4x4 vectors[]);

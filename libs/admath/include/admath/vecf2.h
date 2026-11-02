typedef struct {
  float x, y;
} vecf2;

vecf2 add_vecf2(unsigned int amount, vecf2 vectors[]);
vecf2 subtract_vecf2(unsigned int amount, vecf2 vectors[]);
float cross_product_vecf2(unsigned int amount, vecf2 vectors[]);

float get_length_vecf2(vecf2 vector);
vecf2 normalize_vec2f(vecf2 vector);

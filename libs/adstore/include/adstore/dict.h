#pragma once

#include <adstore/list.h>
#include <cstddef>

typedef struct {
  adlist list;
  size_t data_size;
} cdict;

cdict create_cdict(size_t size_data);
void set_item_dict(cdict* dict, char* key, void* data);
void* get_item_dict(cdict* dict, char* key);

size_t get_str_hash(const char* str);

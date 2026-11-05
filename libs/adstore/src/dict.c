#include "adstore/list.h"
#include <adstore/dict.h>
#include <cstddef>
#include <iterator>


cdict create_cdict(size_t size_data){
  return cdict { create_adlist(0, size_data), size_data };
}

size_t get_str_hash(const char *str){
  size_t hash = 5381;
  int c;
  const char* ptr = str;

  while (*ptr != '\0'){
    c = *ptr;
    hash = ((hash << 5) + hash) + c;
    ptr++;
  }
  
  return hash % 2048;
}

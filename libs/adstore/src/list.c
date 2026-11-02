#include "../include/list.h"
#include <cstddef>
#include <stdlib.h>
#include <string.h>
#define size_t int

list create_list(size_t capacity, size_t size_data) {
  return (list){malloc(capacity * size_data), capacity, size_data, capacity};
}
void delete_list(list *target_list) {
  free(target_list->data);
  target_list = (list){NULL, 0, 0, 0};
}

void *get_list_element(const list *list, size_t index) {
  return list->data + (index * list->size_data);
}
void set_list_element(list *list, size_t amount, void *data, size_t index) {
  memcpy((list->data + (index * list->size_data)), data,
         amount * list->size_data);
}
void resize_list(list *list, size_t new_capacity) {
  list->capacity = new_capacity;
  if (list->real_capacity < new_capacity) {
    list->data = realloc(list->data, new_capacity);
    list->real_capacity = new_capacity;
  }
}

void append_list(list *list, size_t amount, void *data) {}
void *pop_list(list *list);
void push_list(list *list);

void remove_at(list *list, size_t index);

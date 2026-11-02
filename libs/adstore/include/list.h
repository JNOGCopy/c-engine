#pragma once

#include <cstddef>
#include <iterator>

typedef struct {
  void *data;
  size_t capacity;
  size_t size_data;
  size_t real_capacity;
} list;

list create_list(size_t capacity, size_t size_data);
void delete_list(list *list);

void *get_list_element(const list *list, size_t index);
void set_list_element(list *list, size_t amount, void *data, size_t index);
void resize_list(list *list, size_t new_capacity);

void append_list(list *list, size_t amount, void *data);
void *pop_list(list *list);
void push_list(list *list);

void remove_at(list *list, size_t index);

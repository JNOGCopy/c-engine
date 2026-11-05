#pragma once

#include <cstddef>
#include <stdbool.h>

#define CREATE_ADLIST(type, capacity) create_adlist(capacity, sizeof(type))
#define GET_ELEMENT_ADLIST(type, adlist, index) *(type*) get_adlist_element(adlist, index)
#define SET_ELEMENT_ADLIST(type, adlist, element, index) set_adlist_element(adlist, 1, (void*)element, index)
#define POP_ELEMENT(type, adlist) *(type *)get_adlist_element(adlist, get_adlist_capacity(adlist)-1); remove_at_adlist(adlist, get_adlist_capacity(adlist)-1)

typedef struct {
  void *data;
  size_t* capacity;
  size_t* size_data;
  size_t* real_capacity;
} adlist;

size_t get_adlist_capacity(const adlist* list);

adlist create_adlist(size_t capacity, size_t size_data);
void delete_adlist(adlist *list);

void *get_adlist_element(const adlist *list, size_t index);
void set_adlist_element(adlist *list, size_t amount, void *data, size_t index);
void resize_adlist(adlist *list, size_t new_capacity);

void append_adlist(adlist *list, size_t amount, void *data);
void pop_adlist(adlist *list);
void push_adlist(adlist *list, size_t amount, void* data);

void remove_at_adlist(adlist *list, size_t index);
bool is_adlist_empty(const adlist *list);

#include <adstore/list.h>
#include <cstddef>
#include <iterator>
#include <stdlib.h>
#include <string.h>

// We use heap variables so we can copy the list in the stack and still having the same capacity and ref
adlist create_adlist(size_t capacity, size_t size_data) {
  size_t* capacity_ref = (size_t*)calloc(1, sizeof(size_t));
  size_t* size_data_ref = (size_t*)calloc(1, sizeof(size_t));
  size_t* real_capacity_ref = (size_t*)calloc(1, sizeof(size_t));

  *capacity_ref = capacity;
  *size_data_ref = size_data;
  *real_capacity_ref = capacity;

  return (adlist){malloc(capacity * size_data), capacity_ref, size_data_ref, real_capacity_ref};
}
void delete_adlist(adlist *target_list) {
  free(target_list->data);
  free(target_list->capacity);
  free(target_list->size_data);
  free(target_list->real_capacity);
  *target_list = (adlist){NULL, NULL, NULL, NULL};
}

void *get_adlist_element(const adlist *list, size_t index) {
  return list->data + (index * *list->size_data);
}
void set_adlist_element(adlist *list, size_t amount, void *data, size_t index) {
  memcpy((list->data + (index * *list->size_data)), data,
         amount * *list->size_data);
}
void resize_adlist(adlist *list, size_t new_capacity) {
  *list->capacity = new_capacity;
  if (*list->real_capacity < new_capacity) {
    printf("%lu", new_capacity);
    list->data = realloc(list->data, new_capacity * *list->size_data);
    *list->real_capacity = new_capacity;
  }
}

void push_adlist(adlist *list, size_t amount, void* data){
  size_t last_index = *list->capacity;
  resize_adlist(list, *list->capacity + amount);
  set_adlist_element(list, amount, data, last_index);
}

void remove_at_adlist(adlist *list, size_t index){
  memcpy(list->data + sizeof(float) * (index), list->data + sizeof(float) * (index + 1), sizeof(float) * (*list->capacity - index));
  resize_adlist(list, *list->capacity-1);
}

size_t get_adlist_capacity(const adlist *list){
  return *list->capacity;
}
  
bool is_adlist_empty(const adlist *list){
  return *list->capacity <= 0;
}

#include <ctime>
#include <stdio.h>
#include <adstore/list.h>
#include <time.h>

void delay(float num){
  clock_t start_time = clock();

  while(clock() - start_time < num * CLOCKS_PER_SEC);
}

int main(){
  adlist lis = CREATE_ADLIST(int, 11);
  set_adlist_element(&lis, 11, (void*)(int[]){ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 0); 
  while (!is_adlist_empty(&lis)){
    int push = *(int *)get_adlist_element(&lis, 0); remove_at_adlist(&lis, 0);
    push_adlist(&lis, 1, (void*)(int[]) { push });
    for (int i = 0; i < get_adlist_capacity(&lis); i++){
      printf(" %d,", *(int*)get_adlist_element(&lis, i));
    }
    printf("\n");
    delay(0.1f);
  }
  delete_adlist(&lis);
}

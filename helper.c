#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

extern int* GenerateRandomArray(int start,int end,long long size);
extern void TestSorting(sortfunc_p func,char* func_name,int* arr,long long size);
extern int* GenerateNearlyOrderedArray(long long size, int num_swap);
extern void swap(int* arr, int index1, int index2);

static bool IsSorted(int* arr,int size);

/*
 * Public functions
 */

inline void swap(int* arr, int index1, int index2){
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;

  return;
}


int* GenerateRandomArray(int start, int end, long long size){
  srand(time(NULL));
  int* arr = malloc(sizeof(int) * size);
  assert(arr != NULL);
  int range = end - start;
  for (int i = 0; i < size; i++) {
    arr[i] = rand()%range + start;
  }

  return arr;
}


int* GenerateNearlyOrderedArray(long long size, int num_swap){
  srand(time(NULL));
  int* arr = malloc(sizeof(int) * size);
  for (long long i = 0; i < size; i++)
    arr[i] = i;
  for (long long i = 0; i < num_swap; i++) {
    long long index1 = rand()%size;
    long long index2 = rand()%size;
    swap(arr, index1, index2);
  }
  return arr;
}


void TestSorting(sortfunc_p func,char* func_name,int* arr, long long size){
  clock_t t1, t2;

  t1 = clock();
  func(arr, size);
  assert(IsSorted(arr,size));
  /* for (int i = 0 ; i < size; i++) { */
  /*   printf("%d ", arr[i]); */
  /* } */
  /* printf("\n"); */
  t2 = clock();

  float diff = ((float)(t2 - t1) / 1000000.0F );
  /* printf("%f",diff); */

  printf("%s: %f seconds. Size: %lld\n", func_name, diff, size);
}

/*
 * Private functions
 */

bool IsSorted(int* arr, int size){
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i-1]) {
      return false;
    }
  }
  return true;
}

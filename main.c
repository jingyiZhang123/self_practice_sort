#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "sortingalgo.h"

#define ARR_SIZE 3100000


int main(int argc, char *argv[]){

  int* arr = GenerateNearlyOrderedArray(ARR_SIZE, 500);
  TestSorting(MergeSort_Int,   "MergeSort        (Nearly Sort)", arr, ARR_SIZE);
  free(arr);
  arr = GenerateNearlyOrderedArray(ARR_SIZE, 500);
  TestSorting(QuickSort_Int,   "QuickSort        (Nearly Sort)", arr, ARR_SIZE);
  free(arr);
  arr = GenerateNearlyOrderedArray(ARR_SIZE, 500);
  TestSorting(ThreeWaySort_Int,"ThreeWaySort_Int (Nearly Sort)", arr, ARR_SIZE);
  free(arr);
  printf("-------------------------------\n");

  arr = GenerateRandomArray(0,ARR_SIZE, ARR_SIZE);
  TestSorting(MergeSort_Int,   "MergeSort        (Normal)     ", arr, ARR_SIZE);
  free(arr);
  arr = GenerateRandomArray(0,ARR_SIZE, ARR_SIZE);
  TestSorting(QuickSort_Int,   "QuickSort        (Normal)     ", arr, ARR_SIZE);
  free(arr);
  arr = GenerateRandomArray(0,ARR_SIZE, ARR_SIZE);
  TestSorting(ThreeWaySort_Int,"ThreeWaySort_Int (Normal)     ", arr, ARR_SIZE);
  free(arr);
  printf("-------------------------------\n");


  arr = GenerateRandomArray(0,256, ARR_SIZE);
  TestSorting(MergeSort_Int,   "MergeSort        (Duplicate   ", arr, ARR_SIZE);
  free(arr);
  arr = GenerateRandomArray(0,256, ARR_SIZE);
  TestSorting(ThreeWaySort_Int,"ThreeWaySort_Int (Duplicates) ", arr, ARR_SIZE);
  free(arr);
  printf("-------------------------------\n");

  return 0;
}

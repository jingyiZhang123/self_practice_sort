#ifndef HELPER_H
#define HELPER_H

typedef void (*sortfunc_p)(int*, int);

int* GenerateRandomArray(int start, int end, long long size);
void TestSorting(sortfunc_p func, char* func_name, int*arr, long long size);
int* GenerateNearlyOrderedArray(long long size, int num_swap);
void swap(int* arr, int index1, int index2);


#endif

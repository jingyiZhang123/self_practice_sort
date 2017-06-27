#include <stdio.h>
#include <stdlib.h>

#include "sortingalgo.h"
#include "helper.h"

extern void InsertSort_Int(int* arr, int size);
extern void MergeSort_Int(int* arr, int size);
extern void QuickSort_Int(int* arr, int size);
extern void ThreeWaySort_Int(int* arr, int size);


static void InsertSort_helper(int* arr, int start, int end);

static void _merge(int* arr, int left, int mid, int right);
static void _merge_sort(int left, int right, int* arr);

static int _partition(int* arr, int left, int right);
static void _quick_sort(int* arr, int left, int right);

static void _threeway_partition(int* arr, int left, int right, int* i_p, int* k_p);
static void _threeway_sort(int* arr, int left, int right);



/*
 * Public funtions
 */

void InsertSort_Int(int* arr, int size){
    for(int i=1; i < size; i++){
        int j;
        int record_value = arr[i];
        for (j = i; j > 0; j--) {
            if(record_value < arr[j-1]){
                arr[j] = arr[j-1];
            }
            else
                break;
        }
        arr[j] = record_value;
    }
}


void MergeSort_Int(int* arr, int size){
  _merge_sort(0,size-1,arr);
}


void QuickSort_Int(int* arr, int size){
  _quick_sort(arr, 0, size-1);
}


void ThreeWaySort_Int(int* arr, int size){
  _threeway_sort(arr, 0, size-1);
}

/*
 * Private funtions
 */

void _threeway_partition(int* arr, int left, int right, int* i_p, int* k_p){
    swap(arr, left, rand()%(right-left+1)+left);
    int pivat = arr[left];
    *i_p = left;
    *k_p = right+1;
    int j = left+1;
    while(j < (*k_p)){
        if(arr[j] > pivat)
            swap(arr, --(*k_p), j);
        else if(arr[j] < pivat)
            swap(arr, ((*i_p)++)+1, j++);
        else
            j ++;
    }
    swap(arr, *i_p, left);
    return;
}



void InsertSort_helper(int* arr, int start, int end){
    for(int i=start+1; i <= end; i++){
        int j;
        int record_value = arr[i];
        for (j = i; j > start; j--) {
            if(record_value < arr[j-1]){
                arr[j] = arr[j-1];
            }
            else
                break;
        }
        arr[j] = record_value;
    }
}

void _threeway_sort(int* arr, int left, int right){
    if(right - left <= 15){
        InsertSort_helper(arr, left, right);
        return;
    }
    int i,k = 0;
    _threeway_partition(arr, left, right, &i, &k);
    _threeway_sort(arr, left, i - 1);
    _threeway_sort(arr, k, right);
}


void _merge(int* arr, int left, int mid, int right){
  int aux[right-left+1];
  for (int i = 0; i <= (right-left); i++)
    aux[i] = arr[i+left];

  int i = 0;
  int j = mid - left + 1;
  for (int k = 0; k <= (right-left); k++) {
    if (i > (mid - left))
      arr[k+left] = aux[j++];

    else if(j > (right - left))
      arr[k+left] = aux[i++];

    else if(aux[i] < aux[j])
      arr[k+left] = aux[i++];
    else
      arr[k+left] = aux[j++];
  }

}


void _merge_sort(int left, int right, int* arr){
  if(right - left <= 15){
    InsertSort_helper(arr,left,right);
    return;
  }

  int mid = left + (right - left)/2;

  _merge_sort(left, mid, arr);
  _merge_sort(mid+1, right, arr);
  if(arr[mid] > arr[mid+1])
    _merge(arr,left,mid,right);

}

int _partition(int* arr, int left, int right){
    swap(arr, left, rand()%(right-left+1)+left);
    int pivat = arr[left];
    int i = left;
    for (int j = left + 1; j <= right; j++) {
        if(arr[j] < pivat)
            swap(arr, (i++)+1, j);
    }
    swap(arr, left, i);
    return i;

}

void _quick_sort(int* arr, int left, int right){
    if(right - left <= 12){
        InsertSort_helper(arr, left, right);
        return;
    }

    int i = _partition(arr, left, right);
    _quick_sort(arr, left, i-1);
    _quick_sort(arr, i+1, right);
}



/* void _merge(int* arr, int left, int mid, int right){ */
/*   int new_arr[right - left + 1]; */
/*   for(int i=left; i<=right; i++) */
/*     new_arr[i-left] = arr[i]; */

/*   int i = left; */
/*   int j = mid + 1; */
/*   for(int k = left; k <= right; k ++){ */
/*     if(i > mid){ */
/*       arr[k] = new_arr[j-left]; */
/*       j ++; */
/*     } */
/*     else if (j > right){ */
/*       arr[k] = new_arr[i-left]; */
/*       i ++; */
/*     } */
/*     else if(new_arr[i - left] < new_arr[j - left]){ */
/*       arr[k] = new_arr[i-left]; */
/*       i ++; */
/*     } */
/*     else{ */
/*       arr[k] = new_arr[j-left]; */
/*       j ++; */
/*     } */
/*   } */
/* } */

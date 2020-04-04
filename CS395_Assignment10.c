/***************************************************************************************************************
 * Id: oste1799
 * Purpose:
 *  *  This program implements an algorithm that does a quick sort with Hoare's partition algorithm
 * Input:
 *  ./assignment10 # # # ... where # are the integers of the array. Ex. ./assignment10 3 5 2
 * Output:
 *  array sorted in nondecreasing order
 *  Partition of A[1..r], with the split position returned as this functions value
 * Compile:
 *  ex. gcc -Wall -o assignment10 assignment10.c
 *
 ***************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void quickSort(int *, int, int);
int hoarePartition(int *, int, int);
void printArray(int *, int, int);
int main(int argc, char *argv[]){
   int size = argc - 1;
   int i;
   int low = 0;
   if(argc < 2)
   {
      printf("Not enough values to sort. Please enter more values.");
      return 0;
   }
   int *arr = malloc(sizeof(int)*size); // dynamic memory allocation for integer array of size argc-1
   for(i = 0; i < size; i++)
   {
      arr[i] = atoi(argv[i+1]);
   }
   quickSort(arr, low, size - 1);
   printArray(arr, 0, size - 1);
   free(arr);
   return 0;
}
// this function prints the array
void printArray(int *arr, int left, int size){
   int i;
   for(i = left; i <= size; i++)
   {
      printf("%i ", arr[i]); // prints array element at i position in the array
   }
   printf("\n");
}
// this function uses the Hoare algorithm to do a quicksort of the passed in array
void quickSort(int *arr, int low, int high){
   int s; // split position
   if(high > low)
   {
      s = hoarePartition(arr, low, high);
      quickSort(arr, low, s - 1);
      quickSort(arr, s + 1, high);
      printArray(arr, low, high);
   }
}
// hoare partition function
int hoarePartition(int *arr, int low, int high){
   int temp;
   int pivot = arr[low]; // pivot is shifted to the right as the values below low val are ordered.
   int i = low;
   int j = high + 1;
   do
   {
      do
      {
         i++;
      }while(arr[i] < pivot);
      do
      {
         j--;
      }while(arr[j] > pivot);
      temp = arr[i]; // temp value to hold the i value about to be swapped
      arr[i] = arr[j]; // swap of the i and j vals
      arr[j] = temp; // j returned to i value
   }while(i < j);
   // swap i, j
   temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
   // swap low, j
   temp = arr[low];
   arr[low] = arr[j];
   arr[j] = temp;
   return (j);
}

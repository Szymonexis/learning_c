#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int pointersSize = 2;
  void** pointers = calloc(pointersSize, sizeof(int*));
  int sizeA = 10;
  int sizeB = 10;

  int* arrayA = getRandomArray(sizeA);
  int* arrayB = getRandomArray(sizeB);
  pointers[0] = arrayA;
  pointers[1] = arrayB;

  // merge();

  freeAll(pointers, pointersSize);
  return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  if (nums2Size == 0) {
    nums1
  }
}

int* getRandomArray(int size) {
  srand(time(NULL));
  int* array = (int*)malloc(size * sizeof(int));

  if (array == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    int randomNumber = rand() % (100 * i + 1);
    array[i] = randomNumber;
  }

  return array;
}

void freeAll(void** pointers, int size) {
  for (int i = 0; i < size; ++i) {
    free(pointers[i]);
  }
  free(pointers);
}
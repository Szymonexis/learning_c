#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

// Function declarations
int* getRandomArray(int size);
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void freeAll(void** pointers, int size);

#endif  // MAIN_H

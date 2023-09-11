#include "generic_array.h"

#include <stdio.h>
#include <stdlib.h>

void initArray(GenericArray* arr, size_t initialSize, size_t itemSize) {
  arr->data = malloc(initialSize * itemSize);
  arr->itemSize = itemSize;
  arr->size = 0;
  arr->capacity = initialSize;
}

void appendElement(GenericArray* arr, void* item) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, arr->capacity * arr->itemSize);
  }

  arr->data[arr->size] = malloc(arr->itemSize);
  memcpy(arr->data[arr->size++], item, arr->itemSize);
}

void* popElement(GenericArray* arr) {
  if (arr->size == 0) {
    return NULL;
  }

  void* item = arr->data[--arr->size];
  arr->data[arr->size] = NULL;

  return item;
}

size_t findIndex(GenericArray* arr, void* item, int (*cmp)(void*, void*)) {
  for (size_t i = 0; i < arr->size; i++) {
    if (cmp(arr->data[i], item) == 0) {
      return i;
    }
  }

  // Not found
  return -1;
}

void removeAtIndex(GenericArray* arr, size_t index) {
  if (index >= arr->size) {
    return;
  }

  free(arr->data[index]);

  for (size_t i = index; i < arr->size - 1; i++) {
    arr->data[i] = arr->data[i + 1];
  }

  arr->data[--arr->size] = NULL;
}

size_t lengthOfArray(GenericArray* arr) { return arr->size; }

void freeArray(GenericArray* arr) {
  for (size_t i = 0; i < arr->size; i++) {
    free(arr->data[i]);
  }

  free(arr->data);

  arr->data = NULL;
  arr->size = arr->capacity = 0;
}

void printArray(GenericArray* arr, ItemFormatter formatter) {
  printf("[ ");

  for (size_t i = 0; i < arr->size; i++) {
    char* formattedItem = formatter(arr->data[i]);

    if (i < arr->size - 1) {
      printf("%s, ", formattedItem);
    } else {
      printf("%s ", formattedItem);
    }

    
    free(formattedItem);
  }

  printf("]\n");
}
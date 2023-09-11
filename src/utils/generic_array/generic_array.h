#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

// TODO: add documentation

typedef char* (*ItemFormatter)(void*);

typedef struct {
  void** data;
  size_t itemSize;
  size_t size;
  size_t capacity;
} GenericArray;

void initArray(GenericArray* arr, size_t initialSize, size_t itemSize);
void appendElement(GenericArray* arr, void* item);
void* popElement(GenericArray* arr);
size_t findIndex(GenericArray* arr, void* item, int (*cmp)(void*, void*));
void removeAtIndex(GenericArray* arr, size_t index);
size_t lengthOfArray(GenericArray* arr);
void freeArray(GenericArray* arr);
void printArray(GenericArray* arr, ItemFormatter formatter);

#endif
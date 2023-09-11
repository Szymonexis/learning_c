#include "main.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/csprintf/csprintf.c"
#include "utils/generic_array/generic_array.c"

int main() {
  // char *formatted_str =
  //     csprintf("Hello %s, number %d and char %c", "World", 123, 'A');
  // printf("%s\n", formatted_str);

  // free(formatted_str);  // Free the allocated memory

  GenericArray intDynamicArr;
  initArray(&intDynamicArr, 1, sizeof(int));

  for (int i = 0; i < 255; i++) {
    appendElement(&intDynamicArr, &i);
  }

  printArray(&intDynamicArr, intFormatter);

  // Don't forget to free the memory allocated
  freeArray(&intDynamicArr);

  return 0;
}

float convert(float value, TYPE type) { return 0.0f; }

char* intFormatter(void* item) {
  char* formatted = malloc(100);
  if (formatted) {
    sprintf(formatted, "%d", *((int*)item));
  }
  return formatted;
}

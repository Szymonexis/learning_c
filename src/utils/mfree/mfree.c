#include "mfree.h"

// @TODO

void mfree(void *chunks[], unsigned long long length) {
  for(unsigned long long i = 0; i < length; i++) {
    free(chunks[i]);
  }
}
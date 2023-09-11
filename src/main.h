// Header guard to prevent double inclusion
#ifndef MAIN_H
#define MAIN_H

typedef enum { F = 'f', C = 'c' } TYPE;

// Function declarations
int main();
float convert(float value, TYPE type);
char* intFormatter(void* item);

#endif  // MAIN_H

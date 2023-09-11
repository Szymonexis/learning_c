#include <math.h>
#include <stdio.h>

float calcFarenheit(float c) { return (c / (5.0 / 9.0) + 32.0); }

float calcCelsius(float f) { return ((5.0 / 9.0) * (f - 32.0)); }

void calcTemp() {
  float userNum = INFINITY;
  char type = '\0';

  printf("Type of conversion (c - Celsius, f - Farenheit): ");
  scanf("%c", &type);

  if (type != 'c' && type != 'f') {
    printf("Wrong type provided\n");
    return;
  }

  printf("Number of degrees (%c): ", type);
  scanf("%f", &userNum);

  if (userNum == INFINITY) {
    printf("You did not provide a number :(\n");
    return;
  }

  switch (type) {
    case 'c': {
      float f = calcFarenheit(userNum);
      printf("%.2f C -> %.2f F\n", userNum, f);
      return;
    }

    case 'f': {
      float c = calcCelsius(userNum);
      printf("%.2f F -> %.2f C\n", userNum, c);
      return;
    }

    default: {
      printf("Wrong type provided\n");
      return;
    }
  }
}

int main() {
  printf("Hello world\n");

  calcTemp();

  return 0;
}

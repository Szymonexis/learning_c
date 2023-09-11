#include <stdarg.h>

char *csprintf(const char *format, ...) {
  va_list args;
  char buffer[500];  // temporary buffer
  char *p = buffer;

  va_start(args, format);
  while (*format) {
    if (*format != '%') {
      *p++ = *format++;
      continue;
    }

    format++;  // move past '%'
    switch (*format) {
      case 'd': {
        int value = va_arg(args, int);
        sprintf(p, "%d", value);
        p += strlen(p);
        break;
      }
      case 'c': {
        char c = va_arg(args, int);  // char is promoted to int in varargs
        *p++ = c;
        break;
      }
      case 's': {
        char *s = va_arg(args, char *);
        strcpy(p, s);
        p += strlen(p);
        break;
      }
      default:
        *p++ = *format;
    }
    format++;
  }

  *p = '\0';  // null terminate the resulting string

  char *result = malloc(strlen(buffer) + 1);
  if (result) {
    strcpy(result, buffer);
  }

  va_end(args);

  return result;  // return dynamically allocated string
}
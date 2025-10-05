#include "../s21_decimal.h"

int last_bit(s21_decimal number) {
  int last_bit = 95;
  while (last_bit >= 0 && get_bit(number, last_bit) == 0) {
    last_bit--;
  }
  return last_bit;
}

int b_last_bit(s21_big_decimal number) {
  int last_bit = 255;
  while (last_bit >= 0 && b_get_bit(number, last_bit) == 0) {
    last_bit--;
  }
  return last_bit;
}
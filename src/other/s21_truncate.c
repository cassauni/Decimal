#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int scale = get_scale(&value);
  int sign = get_sign(&value);

  s21_decimal temp = value;
  unsigned remainder = 0;

  for (int i = 0; i < scale; i++) {
    divide_by_10(&temp, &remainder);
  }

  *result = temp;
  set_sign(result, sign);
  set_scale(result, 0);

  return OK;
}
#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int ret = 0;
  if (result == NULL) {
    ret = 0;
  } else {
    bits_copy(value, result);

    int sign = get_sign(result);

    set_sign(result, !sign);
  }

  return ret;
}
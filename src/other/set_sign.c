#include "../s21_decimal.h"

void set_sign(s21_decimal *value, int sign) {
  unsigned int mask = 1u << 31;
  if (sign != 0)
    value->bits[3] |= mask;
  else
    value->bits[3] &= ~mask;
}
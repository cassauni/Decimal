#include "../s21_decimal.h"

void convertDecimalToBid(s21_decimal value1, s21_big_decimal *value2) {
  value2->b_bits[0] = value1.bits[0];
  value2->b_bits[1] = value1.bits[1];
  value2->b_bits[2] = value1.bits[2];
}

#include "../s21_decimal.h"

int get_sign(const s21_decimal *value) {
  unsigned int mask = 1u << 31;
  return !!(value->bits[3] & mask);
}
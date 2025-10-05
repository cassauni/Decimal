#include "../s21_decimal.h"

void set_bit(s21_decimal *varPtr, int bit, int value) {
  unsigned int mask = 1u << (bit % 32);
  if (bit / 32 < 4 && value) {
    varPtr->bits[bit / 32] |= mask;
  } else if (bit / 32 < 4 && !value) {
    varPtr->bits[bit / 32] &= ~mask;
  }
}

void b_set_bit(s21_big_decimal *varPtr, int bit, int value) {
  unsigned int mask = 1u << (bit % 32);
  if (bit / 32 < 8 && value) {
    varPtr->b_bits[bit / 32] |= mask;
  } else if (bit / 32 < 8 && !value) {
    varPtr->b_bits[bit / 32] &= ~mask;
  }
}
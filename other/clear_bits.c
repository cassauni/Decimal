#include "../s21_decimal.h"

void clear_bits(s21_decimal *val) { memset(val->bits, 0, sizeof(val->bits)); }
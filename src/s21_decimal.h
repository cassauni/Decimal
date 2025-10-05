#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECIMAL_MAX_VALUE 79228162514264337593543950335
#define DECIMAL_MIN_VALUE -79228162514264337593543950335
#define BITS_MAX_VALUE 0xFFFFFFFF
#define DECIMAL_PRECISION 28
#define TRUE 1
#define FALSE 0
#define SIGN 0x80000000
#define ERROR (-1)

enum returns { OK, INF, NEGATIVE_INF, DIVISION_BY_ZERO, CONVERSION_ERROR };
enum converts { SUCCESS, CONVERTING_ERROR };

typedef struct s21_decimal {
  unsigned bits[4];
} s21_decimal;

typedef struct {
  unsigned int b_bits[8];
} s21_big_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int is_zero(s21_decimal value);
void null_decimal(s21_decimal *decimal);
int get_sign(const s21_decimal *value);
void set_sign(s21_decimal *num, int sign);
int get_scale(const s21_decimal *value);
void set_scale(s21_decimal *value, int scale);
int get_bit(s21_decimal num, int bit);
void set_bit(s21_decimal *varPtr, int bit, int value);
int last_bit(s21_decimal number);
void clear_bits(s21_decimal *val);
void bits_copy(s21_decimal src, s21_decimal *dest);
void shift_right(s21_decimal *num, int shift);
int shift_left(s21_decimal *value, int offset);
int normalize(s21_decimal *numDec1, s21_decimal *numDec2);
int correct_last_bits(s21_decimal value);

int b_get_bit(const s21_big_decimal value, int bit);
void b_set_bit(s21_big_decimal *varPtr, int bit, int value);
int b_shift_left(s21_big_decimal *value, int offset);
int b_last_bit(s21_big_decimal number);
int b_multiplication_by_10(s21_big_decimal *dst);
void b_null_decimal(s21_big_decimal *decimal);
void b_shift_right(s21_big_decimal *num, int shift);
int b_is_zero(s21_big_decimal value);
void removing_zeros(s21_decimal *value);

int b_normalize(s21_decimal numDec1, s21_decimal numDec2, s21_big_decimal *dec1,
                s21_big_decimal *dec2, int *scale);
int s21_b_add(s21_big_decimal value_1, s21_big_decimal value_2,
              s21_big_decimal *result);
int s21_b_sub(s21_big_decimal value_1, s21_big_decimal value_2,
              s21_big_decimal *result);
int s21_b_mul(s21_big_decimal value_1, s21_big_decimal value_2,
              s21_big_decimal *result);
int s21_b_div(s21_big_decimal value_1, s21_big_decimal value_2,
              s21_big_decimal *result);
int remains(s21_big_decimal c_result, s21_big_decimal value_1,
            s21_big_decimal value_2, s21_big_decimal *result, int scale);
int different_signs_add(s21_big_decimal big_value_1,
                        s21_big_decimal big_value_2,
                        s21_big_decimal *big_result, int sign_1, int sign_2,
                        int *sign);

int multiplication_by_10(s21_decimal *dst);
void divide_by_10(s21_decimal *in, unsigned *rest);
void big_divide_by_10(s21_big_decimal *in, unsigned *rest);

void convertDecimalToBid(s21_decimal value1, s21_big_decimal *value2);
int convertBigToDecimal(s21_big_decimal value, s21_decimal *result, int *scale);
int bank_round(s21_big_decimal *value, s21_big_decimal value2, unsigned iter,
               unsigned flag);

int big_divide_by_10_rest(s21_big_decimal in);
int divide_by_10_dec(s21_decimal in);

int s21_b_is_greater(s21_big_decimal dec1, s21_big_decimal dec2);
int s21_b_is_equal(s21_big_decimal dec1, s21_big_decimal dec2);

void print_decimal(s21_decimal *dst);
void print_binry(int num);
void b_print_decimal(s21_big_decimal *dst);

#endif
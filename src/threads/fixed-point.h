#ifndef THREADS_FIXED_POINTS_H
#define THREADS_FIXED_POINTS_H

#include <stdint.h>

/* Representação em ponto fixo. */
#define FP_SHIFT 14
#define FP_SCALE (1 << FP_SHIFT)

/* Conversões entre inteiro e ponto fixo. */
#define int_to_fp(n) ((n) * FP_SCALE)
#define fp_to_int(x) ((x) / FP_SCALE)
#define fp_to_int_round(x) ((x) >= 0 ? ((x) + FP_SCALE / 2) / FP_SCALE : ((x) - FP_SCALE / 2) / FP_SCALE)

/* Adição e Subtração em ponto fixo. */
#define fp_add(x, y) ((x) + (y))
#define fp_sub(x, y) ((x) - (y))
#define fp_add_mixed(x, n) ((x) + (n) * FP_SCALE)
#define fp_sub_mixed(x, n) ((x) - (n) * FP_SCALE)

/* Multiplicação em ponto fixo. */
#define fp_mul(x, y) ((int32_t) (((int64_t) (x)) * (y) / FP_SCALE))
#define fp_mul_mixed(x, n) ((x) * (n))

/* Divisão em ponto fixo. */
#define fp_div(x, y) ((int32_t) (((int64_t) (x)) * FP_SCALE / (y)))
#define fp_div_mixed(x, n) ((x) / (n))

#endif
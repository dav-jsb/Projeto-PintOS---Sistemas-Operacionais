#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

/* Fator de conversão para ponto fixo. */
#define F (1 << 14)

/* Conversões de inteiro para ponto fixo e vice-versa*/
#define INT_TO_FIXED(n) ((n) * F)
#define FIXED_TO_INT_ZERO(x) ((x) / F)
#define FIXED_TO_INT_BOUND(x) ((x) >= 0 ? ((x) + F/2) / F : ((x) - F/2) / F)

/* Soma e Subtração. */
#define ADD_FIXED(x, y) ((x) + (y))
#define SUB_FIXED(x, y) ((x) - (y))
#define ADD_INT(x, n) ((x) + (n) * F)
#define SUB_INT(x, n) ((x) - (n) * F)

/* Multiplicação e divisão. */
#define MULT_FIXED(x, y) ((int32_t)(((int64_t)(x)) * (y) / F))
#define MULT_INT(x, n) ((x) * (n))
#define DIV_FIXED(x, y) ((int32_t)(((int64_t)(x)) * F / (y)))
#define DIV_INT(x, n) ((x) / (n))

#endif
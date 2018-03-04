/*
 * Author: Enes Kaya ÖCAL
 * Purpose: 2D vector operations
 * Date : 03.03.2018
 * Language:  C
 */

#ifndef VEC2_H_
#define VEC2_H_
#include<stdio.h>
#include <stdlib.h>

typedef struct VEC2{
	float x;
	float y;
}VEC2;

typedef struct VEC2_SHORT{
	short x;
	short y;
}VEC2_SHORT;

typedef struct VEC2_INT{
	int x;
	int y;
}VEC2_INT;

VEC2* vec2(float x, float y);
void vec2_inc(VEC2* vec, float x, float y);
void vec2_dup(VEC2* vec, float x, float y);


VEC2_SHORT* vec2_short(short x, short y);
void vec2_inc_short(VEC2_SHORT* vec, short x, short y);
void vec2_dup_short(VEC2_SHORT* vec, short x, short y);
void vec2_add_short(VEC2_SHORT* vec, VEC2_SHORT* vec2);
void vec2_set_short(VEC2_SHORT* vec, short x, short y);

VEC2_INT* vec2_int(int x, int y);
void vec2_inc_int(VEC2_INT* vec, int x, int y);
void vec2_dup_int(VEC2_INT* vec, int x, int y);
void vec2_add_int(VEC2_INT* vec, VEC2_INT* vec2);
void vec2_set_int(VEC2_INT* vec, int x, int y);

VEC2* vec2_sum(VEC2* vec, VEC2* vec2);
#endif /* VEC2_H_ */

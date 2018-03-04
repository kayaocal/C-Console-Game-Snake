/*
 * Author: Enes Kaya ÖCAL
 * Purpose: 2D vector operations
 * Date : 03.03.2018
 * Language:  C
 */

#include "vec2.h"

VEC2* vec2(float x, float y)
{
	VEC2* vec = (VEC2*)malloc(sizeof(VEC2));
	vec->x = x;
	vec->y = y;
	return vec;
}

void vec2_inc(VEC2* vec, float x, float y)
{
	vec->x += x;
	vec->y += y;	
}

void vec2_dup(VEC2* vec, float x, float y)
{
	vec->x *= x;
	vec->y *= y;
}

VEC2* vec2_sum(VEC2* vec, VEC2* vec2)
{

}

VEC2_SHORT* vec2_short(short x, short y)
{
	VEC2_SHORT* vec = (VEC2_SHORT*)malloc(sizeof(VEC2_SHORT));
	vec->x = x;
	vec->y = y;
	return vec;
}

void vec2_inc_short(VEC2_SHORT* vec, short x, short y)
{
	vec->x += x;
	vec->y += y;
}

void vec2_dup_short(VEC2_SHORT* vec, short x, short y)
{
	vec->x *= x;
	vec->y *= y;
}

void vec2_add_short(VEC2_SHORT* vec, VEC2_SHORT* vec2)
{
	vec->x += vec2->x;
	vec->y += vec2->y;
}

void vec2_set_short(VEC2_SHORT* vec, short x, short y)
{
	vec->x = x;
	vec->y = y;
}

VEC2_INT* vec2_int(int x, int y)
{
	VEC2_INT* vec = (VEC2_INT*)malloc(sizeof(VEC2_INT));
	vec->x = x;
	vec->y = y;
	return vec;
}

void vec2_inc_int(VEC2_INT* vec, int x, int y)
{
	vec->x += x;
	vec->y += y;
}

void vec2_dup_int(VEC2_INT* vec, int x, int y)
{
	vec->x *= x;
	vec->y *= y;
}

void vec2_add_int(VEC2_INT* vec, VEC2_INT* vec2)
{
	vec->x += vec2->x;
	vec->y += vec2->y;
}

void vec2_set_int(VEC2_INT* vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
}

 

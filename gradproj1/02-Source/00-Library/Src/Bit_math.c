/*
 * Bit_math.c
 *
 Author: Reem
*/

#include "Bit_Math.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return ((x - in_min) * (out_max - out_min) + out_min * (in_max - in_min)) / (in_max - in_min);
}


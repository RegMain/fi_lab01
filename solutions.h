#pragma once
#include <stdint.h>

union f2i {
  float f;
  uint32_t i;
};

uint32_t problem_nine(uint32_t a, uint32_t b);

union f2i problem_twenty_three(union f2i f2i);

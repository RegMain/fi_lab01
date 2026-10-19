#include <stdio.h>
#include "solutions.h"

void problem_nine() {
  uint32_t a, b;
  printf("Task No. 9: Input two integers\n");
  scanf("%d %d", &a, &b);
  uint32_t c = 0;
  uint32_t carry = 0;
  uint32_t mult = 1;
  while (a > 0 || b > 0) {
    c = mult * ((carry + (a % 3) + (b % 3)) % 3) + c;
    carry = (carry + (a % 3) + (b % 3)) / 3;
    mult *= 3;
    a /= 3;
    b /= 3;
  }
  c = mult * carry + c;
  printf("%d\n", c);
}

void problem_twenty_three() {
  union f2i f2i;
  printf("Task No. 23: Input one float\n");
  scanf("%f", &f2i.f);
  uint32_t i = f2i.i;
  uint32_t exp = (i >> 23) & (((uint32_t)1 << 8) - 1);
  uint32_t sign = i >> 31;
  uint32_t num = i & (((uint32_t)1 << 23) - 1);
  for (int i = 0; i < 6; ++i) {
    int cnt = 0;
    if (exp > 1) {
      while (!(exp & 1)) {
        cnt += 1;
        exp >>= 1;
      }
      exp >>= 1;
      exp <<= cnt + 1;
      exp = exp | (((uint32_t)1 << cnt) - 1);
    } else if (exp == 1) {
      num = (num | (1 << 23)) >> 1;
      exp = 0;   
    } else {
      num >>= 1;
    }
  }
  f2i.i = (((sign << 8) | exp) << 23) | num;
  printf("%.12e\n", f2i.f);
}

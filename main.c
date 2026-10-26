#include <stdio.h>
#include <stdint.h>
#include "solutions.h"

int main() {
  uint32_t a, b;
  printf("Task No. 9: Input two integers\n");
  scanf("%d %d", &a, &b);
  printf("%d\n", problem_nine(a, b));

  union f2i f2i;
  printf("Task No. 23: Input one float\n");
  scanf("%f", &f2i.f);
  printf("%.12e\n", problem_twenty_three(f2i).f);
}

#include <stdio.h>

int A, B;

int main(void)
{
  int a, b, c, d;
  scanf("%d %d", &A, &B);
  a = A * (B % 10);
  b = A * ((B / 10) % 10);
  c = A * (B / 100);
  d = 100 * c + 10 * b + a;
  printf("%d\n%d\n%d\n%d\n", a, b, c, d);
  return 0;
}

#include <stdio.h>

int A, B;

int main(void)
{
  scanf("%d %d", &A, &B);
  printf("%d\n%d\n%d\n%d\n%d\n", A + B, A - B, A * B, A / B, A % B);
  return 0;
}

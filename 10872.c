#include <stdio.h>

int fact(int N)
{
  if(N <= 1) return 1;
  else return N * fact(N - 1);
}

int main(void)
{
  int N = 0;
  scanf("%d", &N);
  printf("%d\n", fact(N));
  return 0;
}

#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);

  printf("%d\n", min(min(N / 2, M), (N + M - K) / 3));
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int N, K;
int * coin;
int sum = 0;

void count(void)
{
  int temp;
  for(int i = N - 1; i >= 0; i--)
  {
    temp = K / coin[i];
    K -= coin[i] * temp;
    sum += temp;
  }
}

int main(void)
{
  scanf("%d%d", &N, &K);
  coin = (int*)malloc(sizeof(int) * N);
  for(int i = 0; i < N; i++) scanf("%d", &coin[i]);
  count();
  printf("%d\n", sum);
  return 0;
}

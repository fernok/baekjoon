#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int N, M;
  int max = 0, sum = 0;
  int *arr;
  scanf("%d %d", &N, &M);
  arr = (int*)malloc(sizeof(int) * N);
  for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
  for(int a = 0; a < N - 2; a++)
  {
    for(int b = a + 1; b < N - 1; b++)
    {
      for(int c = b + 1; c < N; c++)
      {
        sum = arr[a] + arr[b] + arr[c];
        if(sum <= M && sum >= max) max = sum;
      }
    }
  }
  printf("%d\n", max);
  return 0;
}

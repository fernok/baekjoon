#include <stdio.h>
#include <stdlib.h>

int *arr;
int N;

int main(void)
{
  scanf("%d", &N);
  arr = (int*)malloc(sizeof(int) * (N + 1));
  arr[1] = 1;
  arr[2] = 2;
  for(int i = 3; i <= N; i++) arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;

  printf("%d\n", arr[N]);
  return 0;
}

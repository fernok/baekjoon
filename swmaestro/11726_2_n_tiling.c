#include <stdio.h>
#include <stdlib.h>

int *arr;
int N;

int tile(int n)
{
  int a, b;
  if(n == 1) { arr[n] = 1; return 1; }
  if(n == 2) { arr[n] = 2; return 2; }
  if(arr[n - 1] != 0) a = arr[n - 1];
  else a = tile(n - 1);
  if(arr[n - 2] != 0) b = arr[n - 2];
  else b = tile(n - 2);
  arr[n] = (a + b) % 10007;
  return arr[n];

}

int main(void)
{
  scanf("%d", &N);
  arr = (int*)malloc(sizeof(int) * (N + 1));
  for(int i = 0; i <= N; i++) arr[i] = 0;
  arr[0] = N;
  printf("%d\n", tile(N));
  return 0;
}

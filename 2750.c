#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y) {int t; (t) = (x); (x) = (y); (y) = (t);}

int main(void)
{
  int N = 0, min = 0, index = 0;
  int *arr;
  scanf("%d", &N);
  arr = (int*)malloc(sizeof(int) * N);
  for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
  for(int i = 0; i < N - 1; i++)
  {
    min = arr[i];
    index = i;
    for(int j = i + 1; j < N; j++)
    {
      if(arr[j] < min) { min = arr[j]; index = j; }
    }
    SWAP(arr[i], arr[index]);
  }
  for(int i = 0; i < N; i++) printf("%d\n", arr[i]);
  return 0;
}

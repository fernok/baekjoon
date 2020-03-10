#include <stdio.h>
#include <stdlib.h>

int N;
long int *arr;

void sort(void)
{
  int i, j, t;
  int min_index;
  int min = 1000;
  for(int i = 0; i < N; i++)
  {
    min = arr[i];
    for(int j = i; j < N; j++)
    {
      if(arr[j] <= min)
      {
        min_index = j;
        min = arr[j];
      }
    }
    t = arr[i];
    arr[i] = min;
    arr[min_index] = t;
  }
  return;
}

int main(void)
{
  long int sum = 0;
  scanf("%d", &N);
  arr = (long int*)malloc(sizeof(long int) * N);
  for(int i = 0; i < N; i++) scanf("%ld", &arr[i]);
  sort();
  for(int i = 0; i < N; i++)
  {
    for(int j = N - i; j > 0; j--)
    {
      sum += arr[i];
    }
  }
  printf("%ld\n", sum);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int N;
int sum = 0;
int *arr;

void pinary(int prev, int i)
{
  if(i == N - 1) sum++;
  else if(prev == 0)
  {
    i++;
    pinary(0, i);
    pinary(1, i);
  }
  else
  {
    i++;
    pinary(0, i);
  }
  return;
}

int main(void)
{
  scanf("%d", &N);
  arr = (int*)malloc(sizeof(int) * (N - 1));
  pinary(1, 0);
  printf("%d\n", sum);
  return 0;
}

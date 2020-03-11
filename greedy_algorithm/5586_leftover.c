#include <stdio.h>
#include <stdlib.h>

int N;
int money[] = {500, 100, 50, 10, 5, 1};
int result = 0;

void check(void)
{
  int prod = 0;
  for(int i = 0; i < 6; i++)
  {
    prod = N / money[i];
    N -= prod * money[i];
    result += prod;
  }
  return;
}

int main(void)
{
  scanf("%d", &N);
  N = 1000 - N;
  check();
  printf("%d\n", result);
  return 0;
}

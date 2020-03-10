#include <stdio.h>
#include <stdlib.h>

int T;
int *test;
int num[12] = { 0, };

void check(int n)
{
  //int one = 12, two = 12, three = 12;
  if(n == 1) { num[n] = 1; return; }
  if(n - 3 > 0)
  {
    if(num[n - 3] == 0) check(n - 3);
    num[n] += num[n - 3];
  }
  if(n - 2 > 0)
  {
    if(num[n - 2] == 0) check(n - 2);
    num[n] += num[n - 2];
  }
  if(n - 1 > 0)
  {
    if(num[n - 1] == 0) check(n - 1);
    num[n] += num[n - 1];
  }
  return;
}

int main(void)
{
  scanf("%d", &T);
  test = (int*)malloc(sizeof(int) * T);
  for(int i = 0; i < T; i++) { scanf("%d", &test[i]); check(test[i]); }
  for(int i = 0; i < 13; i++) printf("%d\n", num[i]);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _fib {
  int index;
  int zero;
  int one;
} fib_struct;

int T;
fib_struct arr[41];
int *input;


void fibonacci(int a)
{
  if(a == 0) { arr[a].zero = 1; arr[a].one = 0; return; }
  else if(a == 1) { arr[a].one = 1; arr[a].zero = 0; return; }
  else
  {
    if(arr[a - 1].zero == -1) fibonacci(a - 1);
    if(arr[a - 2].zero == -1) fibonacci(a - 2);
    arr[a].zero = arr[a - 1].zero + arr[a - 2].zero;
    arr[a].one = arr[a - 1].one + arr[a - 2].one;
  }
  return;
}

int main(void)
{
  scanf("%d", &T);
  input = (int*)malloc(sizeof(int) * T);
  for(int i = 0; i < 41; i++)
  {
    arr[i].index = i;
    arr[i].zero = -1;
    arr[i].one = -1;
  }
  for(int i = 0; i < T; i++)
  {
    scanf("%d", &input[i]);
  }
  for(int i = 0; i < T; i++)
  {
    fibonacci(arr[input[i]].index);
    printf("%d %d\n", arr[input[i]].zero, arr[input[i]].one);
  }
  return 0;
}

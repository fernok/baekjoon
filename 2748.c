#include <stdio.h>

long int fib_arr[91] = { 0, };

long int fib(int n)
{
  long int a, b;
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(fib_arr[n - 1] != 0) a = fib_arr[n - 1];
  else a = fib(n - 1);
  if(fib_arr[n - 2] != 0) b = fib_arr[n - 2];
  else b = fib(n - 2);
  fib_arr[n] = a + b;
  return fib_arr[n];
}

int main(void)
{
  int n;
  scanf("%d", &n);
  printf("%ld\n", fib(n));
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define COMPARE(x, y, z) ((x) < (MIN((y), (z))) ? (x) : (MIN((y), (z))))

int N;
int *arr;

void check(int n)
{
  int a = N + 1, b = N + 1, c = N + 1;
  if(n == 1) return;
  if(n % 3 == 0)
  {
    if(arr[n / 3] == 0) check(n / 3);
    a = arr[n / 3] + 1;
  }
  if(n % 2 == 0)
  {
    if(arr[n / 2] == 0) check(n / 2);
    b = arr[n / 2] + 1;
  }
  if(n - 1 >= 0)
  {
    if(arr[n - 1] == 0) check(n - 1);
    c = arr[n - 1] + 1;
  }
  arr[n] = COMPARE(a, b, c);
  return;
}

int main(void)
{
  scanf("%d", &N);
  arr = (int*)calloc(N + 1, sizeof(int));
  check(N);
  printf("%d\n", arr[N]);
  return 0;
}

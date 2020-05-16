#include <stdio.h>

int add(int *num, int *count)
{
  int ten = (*num) / 10;
  int one = (*num) % 10;
  int sum = ten + one;
  (*count)++;
  return (one * 10 + sum % 10);
}

int main() {
  int N;
  int count = 0;
  scanf("%d", &N);
  int result = add(&N, &count);
  while(result != N) result = add(&result, &count);
  printf("%d\n", count);
  return 0;
}

#include <stdio.h>

int get_length(int n)
{
  int i = 1; int n_length = 0;
  while(n >= i)
  {
    i *= 10;
    n_length++;
  }
  return n_length;
}

int main(void)
{
  int N, N_length;
  int compare = 0, temp = 0, temp_sum = 0;
  scanf("%d", &N);
  N_length = get_length(N);
  compare = N - (9 * N_length);
  for(compare; compare < N; compare++)
  {
    temp = compare;
    while(temp != 0)
    {
      temp_sum += temp % 10;
      temp /= 10;
    }
    if(temp_sum + compare == N)
    {
      printf("%d\n", compare);
      return 0;
    }
    temp_sum = 0;
  }
  printf("0\n");
  return 0;
}

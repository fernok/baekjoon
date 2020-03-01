#include <stdio.h>

int main(void)
{
  int N = 0, five;
  int product = 0, value = 0, sum = 0;
  scanf("%d", &N);
  product = N / 5;
  for(five = product; five >= 0; five--)
  {
    value = N - (five * 5);
    if((value % 3) == 0)
    {
      sum = five + (value / 3);
      printf("%d", sum);
      return 0;
    }
  }
  printf("-1");
  return 0;
}

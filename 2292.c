#include <stdio.h>

int main(void)
{
  int N = 0, count = 1;
  int temp = 1000000000 / 6;
  scanf("%d", &N);
  for(int i = 0; i < temp; i++)
  {
    count += 6 * i;
    if(count >= N) { printf("%d", i + 1); return 0; }
  }
  return 0;
}

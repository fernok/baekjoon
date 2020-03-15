#include <stdio.h>

int N;

int main(void)
{
  int N;
  int msb, other, i;
  scanf("%d", &N);
  other = N / 2;
  msb = N % 2;
  if(msb == 1) { other--; msb = 7; }
  else { other--; msb = 1; }
  printf("%d", msb);
  for(i = 0; i < other; i++) printf("%d", 1);
  printf("\n");
  return 0;
}

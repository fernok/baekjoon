#include <stdio.h>

void main(void)
{
  long a = 0, b = 0, c = 0;
  scanf("%ld %ld %ld", &a, &b, &c);
  if(b >= c) { printf("-1\n"); return; }
  else printf("%ld\n", (a / (c - b)) + 1);
  return;
}

#include <stdio.h>

int main(void)
{
  long int X;
  long int i = 1;
  long int j = 1;
  int cnt = 0;
  scanf("%ld", &X);
  while(i <= X) { i += j++; cnt++; }
  i -= --j;
  X -= i;
  if(cnt % 2 == 0) printf("%ld/%ld\n", 1 + X, j - X);
  else printf("%ld/%ld\n", j - X, 1 + X);
  return 0;
}

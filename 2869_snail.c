#include <stdio.h>

int main(void)
{
  int A, B, V;
  int cnt, left;
  scanf("%d %d %d", &A, &B, &V);
  cnt = V / (A - B);
  left = V % (A - B);
  while(left <= A)
  {
    cnt--;
    left += (A - B);
    printf("%d, %d\n", cnt, left);
  }
  printf("%d\n", cnt);
  return 0;
}

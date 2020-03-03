#include <stdio.h>

int N;
int arr[11] = { 0, };
int op[4] = { 0, };

int main(void)
{
  int i;
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &arr[i]);
  for(i = 0; i < 4; i++) scanf("%d", &op[i]);
  return 0;
}

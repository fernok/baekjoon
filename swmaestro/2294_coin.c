#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) ((x) > (y)) ? (y) : (x)

int main(void)
{
  int n, k;
  int arr[101], d[100001];
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  for(int i = 1; i <= k; i++) d[i] = 100001;
  d[0] = 0;

  for(int i = 1; i <= n; i++) for(int j = arr[i]; j <= k; j++) d[j] = MIN(d[j], d[j - arr[i]] + 1);

  if(d[k] == 100001) d[k] = -1;
  printf("%d\n", d[k]);
  return 0;
}

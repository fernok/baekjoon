#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct _wine {
  int value;
  int sum;
  int select;
} wine;

int n;
wine *arr;

void find_max(int i)
{
  if(i == 0) { arr[i].sum = arr[i].value; arr[i].select = 1; }
  

}

int main(void)
{
  scanf("%d", &n);
  arr = (wine*)malloc(sizeof(wine) * n);
  for(int i = 0; i < n; i++) { scanf("%d", &arr[i].value); arr[i].sum = 0; }
  find_max(n - 1);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _num {
  int num;
  int size;
} number;

int main(void)
{
  int N, i;
  int cnt = 0;
  number *arr;
  scanf("%d", &N);
  arr = (number*)malloc(sizeof(number) * N);
  for(i = 0; i < N; i++) {scanf("%d", &arr[i].num); arr[i].size = 1;}
  for(i = 0; i < N; i++)
  {
    if
  }

  return 0;
}

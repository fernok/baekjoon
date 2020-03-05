#include <stdio.h>
#include <stdlib.h>

typedef struct _size{
  int weight;
  int height;
  int rank = 0;
} size;
size *arr;

int main(void)
{
  int N;
  scanf("%d", &N);
  arr = (size*)malloc(sizeof(size) * N);
  for(int i = 0; i < N; i++) scanf("%d %d", &arr[i].weight, &arr[i].height);

  return 0;
}

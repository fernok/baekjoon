#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct _tri{
  int value;
  int max_sum;
} item;

int n;
item **triangle;
//int *max_arr;

void get_max(int i, int j)
{
  if(i == 0) triangle[i][j].max_sum = triangle[i][j].value;
  else
  {
    if(j == 0)
    {
      if(triangle[i - 1][j].max_sum == 0) get_max(i - 1, j);
      triangle[i][j].max_sum = triangle[i - 1][j].max_sum + triangle[i][j].value;
      return;
    }
    else if(j == i)
    {
      if(triangle[i - 1][i - 1].max_sum == 0) get_max(i - 1, i - 1);
      triangle[i][j].max_sum = triangle[i - 1][i - 1].max_sum + triangle[i][j].value;
      return;
    }
    else
    {
      if(triangle[i - 1][j - 1].max_sum == 0) get_max(i - 1, j - 1);
      if(triangle[i - 1][j].max_sum == 0) get_max(i - 1, j);
      triangle[i][j].max_sum = MAX(triangle[i - 1][j - 1].max_sum, triangle[i - 1][j].max_sum) + triangle[i][j].value;
      return;
    }
  }
}

int main(void)
{
  scanf("%d", &n);
  int size = (n * (n + 1)) / 2;
  int max = 0;
  int i, j;
  triangle = (item**)malloc(sizeof(item*) * n);
  //max_arr = (int*)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++)
  {
    triangle[i] = (item*)malloc(sizeof(item) * n);
    for(j = 0; j <= i; j++ )
    {
      scanf("%d", &triangle[i][j].value);
      triangle[i][j].max_sum = 0;
    }
  }
  for(i = 0; i < n; i++) get_max(n - 1, i);
  for(i = 0; i < n; i++) if(max < triangle[n - 1][i].max_sum) max = triangle[n - 1][i].max_sum;

  printf("%d\n", max);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _conference {
  int start;
  int end;
  int time;
} conf;

int N;
conf *arr;
int *time;
int result = 0;

void sort(void)
{
  int i, j;
  conf t;
  int min_index;
  int min = 1000;
  for(int i = 0; i < N; i++)
  {
    min = arr[i].time;
    for(int j = i; j < N; j++)
    {
      if(arr[j].time <= min)
      {
        min_index = j;
        min = arr[j].time;
      }
    }
    t = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = t;
  }
  return;
}

void check_max(void)
{
  int is_empty = 0;
  int i, j;
  for(i = 0; i < N; i++)
  {
    for(j = arr[i].start; j < arr[i].end; j++)
    {
      if(time[j] != 0) is_empty++;
    }
    if(is_empty == 0)
    {
      result++;
      for(j = arr[i].start; j < arr[i].end; j++) time[j] = 1;
    }
    is_empty = 0;
  }
  return;
}

int main(void)
{
  int max_time = 0;
  scanf("%d", &N);
  arr = (conf*)malloc(sizeof(conf) * N);
  for(int i = 0; i < N; i++)
  {
    scanf("%d%d", &arr[i].start, &arr[i].end);
    arr[i].time = arr[i].start + arr[i].end;
    if(arr[i].end > max_time) max_time = arr[i].end;
  }
  time = (int*)calloc(max_time, sizeof(int));
  sort();
  check_max();
  printf("%d\n", result);
  return 0;
}

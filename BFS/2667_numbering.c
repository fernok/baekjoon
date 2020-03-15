#include <stdio.h>
#include <stdlib.h>

typedef struct _queue {
  int x;
  int y;
} que;

int N;
int **arr;
// 단지내 집의 수
int *cnt;
// 단지의 수
int ind = 0;
que *queue;

void reset_queue(void)
{
  for(int i = 0; i < N; i++) { queue[i].x = 0; queue[i].y = 0; }
  return;
}

void BFS(int i, int j)
{
  int front = 0, rear = 0;
  int tmp;
  que pop;
  arr[i][j] = 0;
  cnt[ind]++;
  queue[0].x = i; queue[0].y = j;
  rear++;
  while(front < rear)
  {
    pop.x = queue[front].x; pop.y = queue[front].y;
    front++;
    if(arr[pop.x - 1][pop.y] == 1) { cnt[ind]++; queue[rear].x = pop.x - 1; queue[rear].y = pop.y; rear++; arr[pop.x - 1][pop.y] = 0; }
    if(arr[pop.x][pop.y - 1] == 1) { cnt[ind]++; queue[rear].x = pop.x; queue[rear].y = pop.y - 1; rear++; arr[pop.x][pop.y - 1] = 0; }
    if(arr[pop.x][pop.y + 1] == 1) { cnt[ind]++; queue[rear].x = pop.x; queue[rear].y = pop.y + 1; rear++; arr[pop.x][pop.y + 1] = 0; }
    if(arr[pop.x + 1][pop.y] == 1) { cnt[ind]++; queue[rear].x = pop.x + 1; queue[rear].y = pop.y; rear++; arr[pop.x + 1][pop.y] = 0; }
  }
  reset_queue();
  ind++;
  return;
}

void sort(void)
{
  int min = 626;
  int i, j;
  int tmp;
  int minindex = 0;
  for(i = 0; i < ind; i++)
  {
    minindex = i;
    min = cnt[i];
    for(j = i; j < ind; j++)
    {
      if(cnt[j] < min) {minindex = j; min = cnt[j];}
    }
    tmp = cnt[i];
    cnt[i] = min;
    cnt[minindex] = tmp;
  }
  return;
}

int main(void)
{
  int i, j;
  scanf("%d", &N);
  cnt = (int*)calloc(N * N, sizeof(int));
  queue = (que*)calloc(N * N, sizeof(que));
  arr = (int**)malloc(sizeof(int*) * (N + 2));
  for(i = 0; i <= N + 1; i++)
  {
    arr[i] = (int*)calloc(N + 2, sizeof(int));
    if(i != 0 && i != N + 1)
    {
      for(j = 1; j < N + 1; j++) scanf("%1d", &arr[i][j]);
    }
  }
  for(i = 1; i <= N; i++)
  {
    for(j = 1; j <= N; j++)
    {
      if(arr[i][j]) BFS(i, j);
    }
  }

  sort();

  printf("%d\n", ind);
  for(i = 0; i < ind; i++) printf("%d\n", cnt[i]);

  return 0;
}

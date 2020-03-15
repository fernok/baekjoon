#include <stdio.h>
#include <stdlib.h>

int **graph;
int *visited;
int N, M, V;
int *queue;
int first = 0, last = 0;

void DFS(int v)
{
  visited[v] = 1;
  printf("%d ", v);
  for(int i = 1; i <= N; i++)
  {
    if(visited[i] == 0 && graph[v][i] == 1) DFS(i);
  }
  return;
}

void BFS(int v)
{
  int pop = 0;
  printf("%d ", v);
  visited[v] = 1;
  queue[0] = v;
  last++;
  while(first < last)
  {
    pop = queue[first];
    first++;
    for(int i = 1; i <= N; i++)
    {
      if(graph[pop][i] == 1 && visited[i] == 0)
      {
        printf("%d ", i);
        queue[last] = i;
        last++;
        visited[i] = 1;
      }
    }
  }
  return;
}

int main(void)
{
  int i;
  int start, end;
  scanf("%d %d %d", &N, &M, &V);
  graph = (int**)malloc(sizeof(int*) * (N + 1));
  for(i = 0; i <= N; i++) graph[i] = (int*)calloc(N + 1, sizeof(int));
  visited = (int*)calloc(N + 1, sizeof(int));
  queue = (int*)calloc(N + 1, sizeof(int));

  for(i = 0; i < M; i++)
  {
    scanf("%d %d", &start, &end);
    graph[start][end] = 1;
    graph[end][start] = 1;
  }
  DFS(V);
  for(i = 0; i <= N; i++) visited[i] = 0;
  printf("\n");
  BFS(V);

  return 0;
}

#include <stdio.h>

int N, M;
int visited[9] = { 0, };
int arr[9] = { 0, };

void func(int cnt)
{
  if(cnt == M)
  {
    for(int i = 0; i < M; i++) printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  for(int i = 1; i <= N; i++)
  {
    if(visited[i] == 0)
    {
      visited[i] = 1;
      arr[cnt] = i;
      func(cnt + 1);
      for(int j = i + 1; j <= N; j++) visited[j] = 0;
    }
  }
}

int main(void) {
  scanf("%d %d", &N, &M);
  func(0);
  return 0;
}

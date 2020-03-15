#include <stdio.h>
#include <stdlib.h>

int N, M, T;
int **arr;
int *answer;


void check(int k)
{
  int i, j;
  for(i = 1; i <= N; i++)
  {
    for(j = 1; j <= M; j++)
    {
      if(arr[i][j] == 1)
      {
        if((arr[i - 1][j - 1] == 1 && arr[i - 1][j] == 1 && arr[i][j - 1] == 1) || (arr[i - 1][j] == 1 && arr[i - 1][j + 1] == 1 && arr[i][j + 1] == 1) || (arr[i][j - 1] == 1 && arr[i + 1][j - 1] == 1 && arr[i + 1][j] == 1) || (arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1)) continue;
        else { answer[k] = 0; return; }
      }
    }
  }
  answer[k] = 1;
  return;
}

int main(void)
{
  int i, j, k;
  scanf("%d", &T);
  answer = (int*)calloc(T, sizeof(int));
  for(i = 0; i < T; i++)
  {
    scanf("%d%d", &N, &M);
    arr = (int**)malloc(sizeof(int*) * (N + 2));
    for(j = 0; j < N + 2; j++) arr[j] = (int*)calloc(M + 2, sizeof(int));
    for(j = 1; j < N + 1; j++)
    {
      for(k = 1; k < M + 1; k++) scanf("%d", &arr[j][k]);
    }

    check(i);

    for(j = 0; j < M; j++) free(arr[j]);
    free(arr);
  }
  for(i = 0; i < T; i++)
  {
    if(answer[i] == 1) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

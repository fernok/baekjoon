#include <stdio.h>
#include <stdlib.h>

char **board;
int min = 64;

void change(char *bw)
{
  if(*bw == 'B') *bw = 'W';
  else *bw = 'B';
  return;
}

void check(int i, int j)
{
  char bw = 'B';
  int cnt = 1;
  int result = 0;
  while(cnt >= 0)
  {
    for(int a = i; a < i + 8; a++)
    {
      for(int b = j; b < j + 8; b++)
      {
        if(board[a][b] != bw) result++;
        change(&bw);
      }
      change(&bw);
    }
    if(result <= min) min = result;
    result = 0;
    cnt--;
    change(&bw);
  }
  return;
}

int main(void)
{
  int N, M;
  scanf("%d %d", &N, &M);
  board = (char**)malloc(sizeof(char*) * N);
  for(int i = 0; i < N; i++) board[i] = (char*)malloc(sizeof(char) * (M + 1));
  for(int i = 0; i < N; i++) { scanf("%s", board[i]); board[i][M] = '\0'; }
  for(int i = 0; i <= M - 8; i++)
  {
    for(int j = 0; j <= N - 8; j++)
    {
      check(i, j);
    }
  }
  printf("%d\n", min);
  return 0;
}

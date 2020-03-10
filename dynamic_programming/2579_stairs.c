#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct _stair{
  int score;
  int sum;
  int is_onetwo;
} stair;

int N;
stair *stairs;

void get_max(int i)
{
  int one = 0, two = 0;
  if(i == 1) { stairs[i].sum = stairs[i].score; stairs[i].is_onetwo = 2; return; }
  if(stairs[i - 2].sum == -1) get_max(i - 2);
  two = stairs[i - 2].sum;
  if(stairs[i - 1].sum == -1) get_max(i - 1);
  if(stairs[i - 1].is_onetwo == 1) one = 0;
  else one = stairs[i - 1].sum;
  if(two > one){
    stairs[i].sum = two + stairs[i].score;
    stairs[i].is_onetwo = 2;
  }
  else {
    stairs[i].sum = one + stairs[i].score;
    stairs[i].is_onetwo = 1;
  }
}

int main(void)
{
  scanf("%d", &N);
  stairs = (stair*)malloc(sizeof(stair) * (N + 1));

  stairs[0].score = 0;
  stairs[0].sum = 0;
  stairs[0].is_onetwo = 0;
  for(int i = 1; i <= N; i++) { scanf("%d", &stairs[i].score); stairs[i].sum = -1; stairs[i].is_onetwo = -1; }

  get_max(N);

  printf("%d\n", stairs[N].sum);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x) > (y)) ? (x) : (y)

int N, K;
typedef struct _object {
  int weight;
  int value;
} object;
object *obj_arr;
int **val_arr;

void knapsack(int i, int j)
{
  int weight = obj_arr[i - 1].weight;
  int value = obj_arr[i - 1].value;
  if(i == 0 || j == 0) { val_arr[i][j] = 0; return; }
  if((j - weight) < 0) { val_arr[i][j] = val_arr[i - 1][j]; return; }
  else { val_arr[i][j] = MAX(val_arr[i - 1][j], value + val_arr[i - 1][j - weight]); return; }
}

int main(void)
{
  scanf("%d %d", &N, &K);
  obj_arr = (object*)malloc(sizeof(object) * N);
  val_arr = (int**)malloc(sizeof(int*) * (N + 1));
  for(int i = 0; i <= N; i++) val_arr[i] = (int*)malloc(sizeof(int) * (K + 1));
  for(int i = 0; i < N; i++) scanf("%d %d", &obj_arr[i].weight, &obj_arr[i].value);
  for(int i = 0; i <= N; i++) for(int j = 0; j <= K; j++) knapsack(i, j);
  printf("%d\n", val_arr[N][K]);
  return 0;
}

#include <stdio.h>

int N, K;
int arr[3001];
int diff_arr[3000];
int cutpoint[3000];
int max;
int max_index;
int sum = 0;
int front = 0;
int last_index = 0;

int main(void)
{
  int i, j;
  scanf("%d %d", &N, &K);
  for (i = 0; i < N; i++)
  {
    scanf("%d", &arr[i]);
    if (i == 0) continue;
    diff_arr[i - 1] = arr[i] - arr[i - 1];
  }

  for (i = 0; i < K - 1; i++)
  {
    max = 0;
    for (j = 0; j < N - 1; j++)
    {
      if ((diff_arr[j] > max) && !cutpoint[j])
      {
        max = diff_arr[j];
        max_index = j;
      }
    }
    cutpoint[max_index] = 1;
  }

  for (i = 0; i < N - 1; i++)
  {
    if (front == 0) front = arr[i];
    if (cutpoint[i])
    {
      sum += arr[i] - front;
      front = 0;
      last_index = i;
    }
  }
  sum += arr[N - 1] - arr[last_index + 1];
  printf("%d\n", sum);
  return 0;
}

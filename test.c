#include <stdio.h>
#include <stdlib.h>

int N, K;
int *arr;

int main() {
	int i;
	int min;
	// 가장 작은 1의 왼쪽과 오른쪽에 있는 원소의 개수
	int left, right;
  int left_tmp, right_tmp;
	// 골라야 하는 최소 횟수
	int cnt = 0;
  int mincnt = 100000;
  int prod;
	scanf("%d%d", &N, &K);
  arr = (int*)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] == 1) min = i;
	}
	left = min;
	right = N - (min + 1);
  for(i = 0; i < K; i++)
  {
    cnt = 0;
    left_tmp = left - (K - i - 1);
    right_tmp = right - i;
    if(left_tmp < 0 || right_tmp < 0) continue;
    cnt++;
    cnt += left_tmp / (K - 1);
    if(left_tmp % (K - 1)) cnt++;
    cnt += right_tmp / (K - 1);
    if(right_tmp % (K - 1)) cnt++;
    if(cnt < mincnt) mincnt = cnt;
  }
  
	printf("%d\n", mincnt);
	return 0;
}

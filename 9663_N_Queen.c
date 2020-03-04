#include <stdio.h>
#include <stdlib.h>

int N;
int **arr;
int count = 0;

void queen(int cnt)
{

}

int main(void)
{
	scanf("%d", &N);
	arr = (int**)malloc(sizeof(int*) * N);
	for(int i = 0; i < N; i++) arr[i] = (int*)malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) arr[i][j] = 0;

	return 0;
}

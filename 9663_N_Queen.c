#include <stdio.h>
#include <stdlib.h>

int count = 0;
int isPromising(int*, int);
void enumerate(int);
void queen(int*, int, int);

int isPromising(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == arr[n]) return 0;
		if((arr[i] - arr[n]) == (n - 1)) return 0;
		if((arr[n] - arr[i]) == (n - 1)) return 0;
	}
	return 1;
}

void enumerate(int n)
{
	int *arr = (int*)malloc(sizeof(int) * n);
	queen(arr, n, 0);
}

void queen(int *arr, int length, int n)
{
	if(n == length) count++;
	else
	{
		for(int i = 0; i < length; i++)
		{
			arr[n] = i;
			if(isPromising(arr, n)) queen(arr, length, n + 1);
		}
	}
}

void main(void)
{
	int n, result;
	scanf("%d", &n);
	if(n < 0 || n >= 15) return;
	enumerate(n);
	printf("%d\n", count);
	return;
}

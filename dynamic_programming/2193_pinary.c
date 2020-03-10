#include <stdio.h>
#include <stdlib.h>

typedef struct _num{
  long int zero;
  long int one;
} num;

int N;
int *arr;
num *numarr;

void pinary(int i)
{
  if(i == 0) { numarr[i].zero = 1; numarr[i].one = 0; return; }
  else
  {
    pinary(i - 1);
    numarr[i].zero = numarr[i - 1].one + numarr[i - 1].zero;
    numarr[i].one = numarr[i - 1].zero;
    return;
  }
}

int main(void)
{
  scanf("%d", &N);
  if(N == 1) { printf("1\n"); return 0; }
  arr = (int*)malloc(sizeof(int) * (N - 1));
  numarr = (num*)malloc(sizeof(num) * (N - 1));
  pinary(N - 2);
  printf("%ld\n", numarr[N - 2].zero + numarr[N - 2].one);
  return 0;
}

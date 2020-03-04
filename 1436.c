#include <stdio.h>

int N;
int cnt = 0;

int check(int n)
{
  int i = 10;
  while(n / i >= 10)
  {
    if((n % i == 6) && ((n / i) % i == 6) && ((n / (i * 10)) % i== 6)) return 1;
    n /= 10;
  }
  return 0;
}

int main(void)
{
  int num = 666;
  scanf("%d", &N);
  while(1){
    if(check(num)) cnt++;
    if(cnt == N) break;
    num++;
  }
  printf("%d\n", num);
  return 0;
}

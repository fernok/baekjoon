#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct _color
{
  int r;
  int g;
  int b;
  int minr;
  int ming;
  int minb;
} color;

int N;
int sum = 0;
color *house;

void min(int i)
{
  if(i == 0) { house[i].minr = house[i].r; house[i].ming = house[i].g; house[i].minb = house[i].b; return; }
  else
  {
    house[i].minr = MIN(house[i - 1].ming + house[i].r, house[i - 1].minb + house[i].r);
    house[i].ming = MIN(house[i - 1].minr + house[i].g, house[i - 1].minb + house[i].g);
    house[i].minb = MIN(house[i - 1].minr + house[i].b, house[i - 1].ming + house[i].b);
  }
}


int main(void)
{
  scanf("%d", &N);
  house = (color*)malloc(sizeof(color) * N);
  for(int i = 0; i < N; i++) scanf("%d%d%d", &house[i].r, &house[i].g, &house[i].b);
  for(int i = 0; i < N; i++) min(i);
  printf("%d\n", MIN(house[N - 1].minr, MIN(house[N - 1].ming, house[N - 1].minb)));
  return 0;
}

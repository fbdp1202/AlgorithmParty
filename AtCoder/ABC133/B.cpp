#include <cstdio>
#include <algorithm>
using namespace std;

#define SQ(x) ((x)*(x))
const int MAX_N=10;

int N, D;
int board[MAX_N][MAX_N];

bool isInterger(int a, int b)
{
  int sum = 0;
  for (int i=0; i<D; i++)
    sum += SQ(board[a][i]-board[b][i]);
  for (int i=0; i<127; i++)
    if (sum == i*i) return true;
  return false;
}

int main()
{
  scanf("%d%d", &N, &D);
  for (int i=0; i<N; i++)
    for (int j=0; j<D; j++)
      scanf("%d", &board[i][j]);
  
  int ret = 0;
  for (int i=0; i<N; i++)
    for (int j=i+1; j<N; j++)
      if (isInterger(i, j))
        ret++;
  printf("%d\n", ret);
  return 0;
}
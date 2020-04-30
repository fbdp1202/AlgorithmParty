// baekjoon 10803
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N=10001;
const int MAX_M=101;
const int MAX_INF=1e9;

int N, M, dp[MAX_N][MAX_M];

int dfs(int h, int w) {
  int &ret = dp[h][w];
  if (ret != -1) return ret;

  ret = MAX_INF;
  if (h >= w*4) return ret = min(ret, dfs(h-w, w) + 1);

  for (int i=1; i<=(h+1)/2; i++)
    ret = min(ret, dfs(i, w) + dfs(h-i, w));

  for (int i=1; i<=(w+1)/2; i++)
    ret = min(ret, dfs(h, i) + dfs(h, w-i));

  return ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &N, &M);
  for (int i=1; i<=100; i++)
    dp[i][i] = 1;

  for (int i=2; i<=10000; i++)
    dp[i][1] = i;
  
  for (int i=2; i<=100; i++)
    dp[1][i] = i;

  printf("%d\n", dfs(N,M));
  return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  int tmp = N, count = 9, start = 1, cur = 0, ret = 0;
  bool check = true;
  while (tmp) {
    if (check) ret += min(N-start+1, count);
    count *= 10;
    start *= 10;
    tmp /= 10;
    check ^= true;
  }
  printf("%d\n", ret);
  return 0;
}
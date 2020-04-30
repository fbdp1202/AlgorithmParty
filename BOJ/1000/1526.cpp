// baekjoon 1526 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int ret=0;

void dfs(int here) {
	if (N < here) return;
	ret = max(ret, here);
	dfs(here*10 + 4);
	dfs(here*10 + 7);
}

int main()
{
	scanf("%d", &N);
	dfs(4);
	dfs(7);
	printf("%d\n", ret);
	return 0;
}
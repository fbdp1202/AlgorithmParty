// baekjoon 5639 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=10001;

int N, arr[MAX_N];

void dfs(int l ,int r) {
	if (l > r) return;

	int root = l;
	int s = l, e = r;
	while (arr[s] >= arr[root]) s++;
	while (arr[e] > arr[root]) e--;
	dfs(s, e);
	dfs(e + 1, r);
	printf("%d\n", arr[root]);
}

int main()
{
	int x;
	while (scanf("%d", &x) != -1) {
		arr[N++] = x;
	}

	dfs(0, N-1);
	return 0;
}
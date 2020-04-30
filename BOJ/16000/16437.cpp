// baekjoon 16437 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 123457
typedef long long ll;

char c;
int N, num, connect, node[MAX_N];
bool visited[MAX_N];
vector<int> parent[MAX_N];

ll dfs(int n) {
	ll ret = node[n];
	visited[n] = true;
	for (int &nx : parent[n]) {
		if (visited[nx]) continue;
		ll tmp = dfs(nx);
		if (tmp > 0) ret += tmp;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=2; i<=N; i++) {
		scanf(" %c %d %d", &c, &num, &connect);
		if (c == 'W') num = -num;
		parent[i].push_back(connect);
		parent[connect].push_back(i);
		node[i] = num;
	}
	printf("%lld\n", dfs(1));

	return 0;
}
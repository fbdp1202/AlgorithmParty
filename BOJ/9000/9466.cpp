// baekjoon 9466 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 100001

int T, N, num, team[MAX_N], uncycle[MAX_N];
bool cycle, visited[MAX_N];

void dfs(int idx) {
	if (uncycle[idx]) {
		uncycle[idx] = false;
		num++;
		dfs(team[idx]);
	}
	if (!visited[idx]) {
		visited[idx] = true;
		uncycle[idx] = true;
		dfs(team[idx]);
	}
	uncycle[idx] = false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		num=0;
		scanf("%d", &N);
		fill(uncycle, uncycle+N+1, false);
		fill(visited, visited+N+1, false);
		for (int i=1; i<=N; i++) {
			scanf("%d", &team[i]);
		}

		for (int i=1; i<=N; i++) {
			if (!visited[i]) {
				dfs(team[i]);
			}
		}

		printf("%d\n", N-num);
	}
	return 0;
}
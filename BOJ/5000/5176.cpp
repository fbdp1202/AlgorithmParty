// baekjoon 5176 yechan
#include <bits/stdc++.h>
using namespace std;

int T;
bool visited[501];

int main() {
	scanf("%d", &T);
	while (T--) {
		int P, M;
		fill(visited, visited+501, false);
		scanf("%d%d", &M, &P);
		int ret = 0;
		for (int i=0; i<M; i++) {
			int x;
			scanf("%d", &x);
			if (visited[x]) ret++;
			visited[x] = true;
		}
		printf("%d\n", ret);
	}
}
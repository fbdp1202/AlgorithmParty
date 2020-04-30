// baekjoon 5567 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 501

int N, M, a, b, adj[MAX_N][MAX_N];
bool visited[MAX_N];

int findFriend(){
	visited[1]=true;
	queue<int> q;
	q.push(1);
	int rst = 0, depth = 0;
	while (q.size()) {
		int qSize = q.size();
		while (qSize--) {
			int curr = q.front(); q.pop();
			for (int i=1; i<=N; i++) {
				if (adj[curr][i] && !visited[i]) {
					visited[i] = true;
					rst++;
					q.push(i);
				}
			}
		}
		depth++;
		if (depth > 1) break;
	}
	return rst;
}

int main() {
	scanf("%d%d",&N, &M);
	while (M--) {
		scanf("%d%d", &a, &b);
		adj[a][b]=1;
		adj[b][a]=1;
	}
	printf("%d\n", findFriend());
	return 0;
}
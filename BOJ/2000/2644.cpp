// baekjoon 2644 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, M, A, B;
vector<int> adj[MAX_N];
bool visited[MAX_N];

int BFS(int here) {
	int depth = 0;
	queue<int> q;
	q.push(here);
	visited[here] = true;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int curr = q.front();
			q.pop();
			if (curr == B) return depth;
			for (int next: adj[curr]) {
				if (visited[next]) continue;
				visited[next] = true;
				q.push(next);
			}
		}
		depth++;
	}
	return -1;
}

int main(){
	scanf("%d", &N);
	scanf("%d%d", &A, &B);
	scanf("%d", &M);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	printf("%d\n", BFS(A));
	return 0;
}
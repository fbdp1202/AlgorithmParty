#include <bits/stdc++.h>
using namespace std;

const int MAX_N=200001;

int N, M, visited[MAX_N];
int connect[MAX_N];
int person[MAX_N];
vector<int> adj[MAX_N];
vector<int> starter;

void BFS() {
	queue<int> Q;
	for (int s : starter)
		Q.push(s);

	int t = 0;
	while (!Q.empty()) {
		int qSize = Q.size();
		for (int i=0; i<qSize; i++) {
			int curr = Q.front();
			Q.pop();
			visited[curr] = t;
			for (int nx: adj[curr]) {
				if (visited[nx] != -1) continue;
				if (person[nx] >= (connect[nx]+1)/2) continue;
				person[nx]++;
				if (person[nx] >= (connect[nx]+1)/2) Q.push(nx);
			}
		}
		t++;
	}
}

int main() {
	scanf("%d", &N);
	fill(visited, visited+N, -1);
	for (int i=0; i<N; i++) {
		while (1) {
			int x;
			scanf("%d", &x);
			if (x == 0) break;
			x--;
			connect[i]++;
			adj[i].push_back(x);
		}
	}

	scanf("%d", &M);
	for (int i=0; i<M; i++) {
		int x;
		scanf("%d", &x);
		x--;
		visited[x] = 0;
		starter.push_back(x);
	}
	BFS();
	for (int i=0; i<N; i++)
		printf("%d ", visited[i]);
	puts("");
	return 0;
}
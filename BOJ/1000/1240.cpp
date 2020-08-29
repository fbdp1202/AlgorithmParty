// baekjoon 1240 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=1001;

int N, M;
vector<P> adj[MAX_N];
bool visited[MAX_N];

int BFS(int here, int dest) {
	memset(visited, 0, sizeof(visited));
	queue<P> q;
	q.push(P(here, 0));
	visited[here]=true;
	while (!q.empty()) {
		int curr_pos = q.front().first;
		int curr_val = q.front().second;
		q.pop();
		for (int i=0; i<adj[curr_pos].size(); i++) {
			int next_pos = adj[curr_pos][i].first;
			int next_val = curr_val + adj[curr_pos][i].second;
			if (next_pos == dest) return next_val;
			if (!visited[next_pos]) {
				visited[next_pos]=true;
				q.push(P(next_pos, next_val));
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N-1; i++) {
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		adj[A].push_back(P(B,C));
		adj[B].push_back(P(A,C));
	}

	for (int i=0; i<M; i++) {
		int A, B;
		scanf("%d%d", &A, &B);

	}

	return 0;
}
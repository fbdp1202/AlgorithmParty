// baekjoon 5214 yechan
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100000
#define MAX_K 1000

int N, K, M, tube, dist[MAX_N+MAX_K+1];
bool visit[MAX_N+MAX_K+1];

vector<vector<int>> node;
queue<int> q;

int main() {
	scanf("%d %d %d", &N, &K, &M);
	node.resize(N+M+1);
	for (int i=N+1; i<N+M+1; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &tube);
			node[i].push_back(tube);
			node[tube].push_back(i);
		}
	}
	q.push(1);
	visit[1]=true;
	while (!q.empty()){
		int p = q.front();
		q.pop();
		if (p == N) break;
		for (int next: node[p]) {
			if (!visit[next]) {
				visit[next] = true;
				dist[next] = dist[p] + 1;
				q.push(next);
			}
		}
	}
	if (!visit[N])	printf("-1");
	else 			printf("%d", dist[N]/2+1);
}

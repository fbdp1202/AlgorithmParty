// baekjoon 11375 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int N, M;
vector<int> adj[MAX_N];
int A[MAX_N], B[MAX_N];
bool visited[MAX_N];

bool dfs(int here) {
	visited[here] = true;
	for (int &next: adj[here]) {
		if (B[next] == -1 || !visited[B[next]] && dfs(B[next])) {
			B[next] = here;
			A[here] = next;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &N, &M);
	fill(A, A+N, -1);
	fill(B, B+M, -1);
	for (int i=0; i<N; i++) {
		int K;
		scanf("%d", &K);
		for (int j=0; j<K; j++) {
			int x;
			scanf("%d", &x);
			adj[i].push_back(x-1);
		}
	}

	int ret = 0;
	for (int i=0; i<N; i++) {
		fill(visited, visited+N, false);
		if (dfs(i)) ret++;
	}
	printf("%d\n", ret);
	return 0;
}
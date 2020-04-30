// baekjoon 11376 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=1001;

int N, M;
int A[MAX_N*2], B[MAX_N];
bool visited[MAX_N*2];
vector<int> adj[MAX_N*2];

bool dfs(int here) {
	visited[here] = true;
	for (int &next: adj[here]) {
		if (B[next] == -1 || !visited[B[next]] && dfs(B[next])) {
			A[here] = next;
			B[next] = here;
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
			adj[i*2].push_back(x-1);
			adj[i*2+1].push_back(x-1);
		}
	}

	int ret = 0;
	for (int i=0; i<N*2; i++) {
		fill(visited, visited+N*2, false);
		if (dfs(i)) ret++;
	}
	printf("%d\n", ret);
	return 0;
}
// baekjoon 3295 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int T;
int N, M;
int A[MAX_N], B[MAX_N];
bool visited[MAX_N];
vector<vector<int>> adj;

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
	scanf("%d", &T);
	while (T--) {
		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));
		scanf("%d%d", &N, &M);
		adj = vector<vector<int>>(N);
		for (int i=0; i<M; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}

		int ret = 0;
		for (int i=0; i<N; i++) {
			if (A[i] == -1) {
				memset(visited, 0, sizeof(visited));
				if (dfs(i)) ret++;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
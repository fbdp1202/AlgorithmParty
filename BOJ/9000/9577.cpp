// baekjoon 9577 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int T;
int N, M;
int A[MAX_N], B[MAX_N];
bool visited[MAX_N];
vector<vector<int>> adj;

int dfs(int here) {
	visited[here] = true;
	for (int &nx: adj[here]) {
		if (B[nx] == -1 || !visited[B[nx]] && dfs(B[nx])) {
			A[here] = nx;
			B[nx] = here;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		adj = vector<vector<int>>(MAX_N);
		scanf("%d%d", &N, &M);
		for (int i=0; i<M; i++) {
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			int a;
			scanf("%d", &a);
			for (int j=0; j<a; j++) {
				int x;
				scanf("%d", &x);
				for (int t=t1; t<t2; t++) {
					adj[t].push_back(x);
				}
			}
		}

		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));
		int t = 0;
		int ret = 0;
		for (t = 0; t<MAX_N; t++) {
			if (A[t] == -1) {
				memset(visited, 0, sizeof(visited));
				if (dfs(t)) ret++;
			}
			if (ret == N) break;
		}
		if (t == MAX_N) puts("-1");
		else printf("%d\n", t+1);
	}
}
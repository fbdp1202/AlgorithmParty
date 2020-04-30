// baekjoon 1017 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=51;
const int MAX_V=2001;

bool isprime[MAX_V];

int N, data[MAX_N];
int A[MAX_N];
bool visited[MAX_N];
vector<int> adj[MAX_N];
int couple;

int dfs(int here) {
	if (here == 0 || here == couple) return false;
	visited[here] = true;
	for (int &next: adj[here]) {
		if (A[next] == -1 || !visited[A[next]] && dfs(A[next])) {
			A[here] = next;
			A[next] = here;
			return true;
		}
	}
	return false;
}

int main() {
	isprime[1] = true;
	for (int i=2; i*i<MAX_V; i++) {
		if (!isprime[i]) {
			for (int j=i*i; j<MAX_V; j+=i) {
				isprime[j]=true;
			}
		}
	}

	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);

	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			if (!isprime[data[i]+data[j]]) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> ans;
	for (int &nx: adj[0]) {
		memset(A, -1, sizeof(A));
		couple = nx;
		A[0] = nx;
		A[nx] = 0;

		int ret = 1;
		for (int i=1; i<N; i++) {
			if (A[i] == -1) {
				memset(visited, 0, sizeof(visited));
				if (dfs(i)) ret++;
			}
		}
		if (ret == N/2) ans.push_back(data[nx]);
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end());
		for (int &v: ans)
			printf("%d ", v);
		puts("");
	} else {
		printf("-1\n");
	}

	return 0;
}
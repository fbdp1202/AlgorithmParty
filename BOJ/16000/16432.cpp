// baekjoon 16432 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=1001;
const int MAX_D=11;

int N;
int dp[MAX_N][MAX_D];
vector<int> adj[MAX_N];
stack<int> st;

int dfs(int here, int pv=0) {
	if (here == N) {
		st.push(pv);
		return 1;
	}
	int &ret = dp[here][pv];
	if (ret != -1) return ret;
	ret = 0;
	for (int &nx: adj[here]) {
		if (nx == pv) continue;
		ret = dfs(here+1, nx);
		if (ret) {
			st.push(pv);
			return ret;
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int M; scanf("%d", &M);
		for (int j=0; j<M; j++) {
			int x; scanf("%d", &x);
			adj[i].push_back(x);
		}
	}

	if (dfs(0,0)) {
		st.pop();
		while (!st.empty()) {
			printf("%d\n", st.top());
			st.pop();
		}
	} else {
		puts("-1");
	}
	return 0;
}
// baekjoon 7535 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N=2001;

int T, N, M;
int dfsn[MAX_N*2], dcnt, sn[MAX_N*2], SN;
vector<vector<int>> adj;
stack<int> st;
bool finished[MAX_N*2];

inline int encode(int n) { return (n < 0) ? -(n+1)*2:n*2-1; }
inline int oppo(int n) { return (n%2) ? n-1 : n+1; }

int dfs(int here) {
	int ret = dfsn[here] = ++dcnt;
	st.push(here);

	for (int there: adj[here]) {
		if (!dfsn[there]) ret = min(ret, dfs(there));
		else if (!finished[there]) ret = min(ret,  dfsn[there]);
	}

	if (dfsn[here] == ret) {
		while (1) {
			int t = st.top();
			st.pop();
			sn[t] = SN;
			finished[t] = true;
			if (t == here) break;
		}
		SN++;
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Scenario #%d:\n", t);
		SN = dcnt = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, 0, sizeof(finished));
		scanf("%d%d", &N, &M);
		adj = vector<vector<int>>(N*2);
		for (int i=0; i<M; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u = encode(u);
			v = encode(v);
			adj[oppo(u)].push_back(v);
			adj[u].push_back(oppo(v));
			adj[oppo(v)].push_back(u);
			adj[v].push_back(oppo(u));
		}

		for (int i=0; i<N*2; i++)
			if (!dfsn[i]) dfs(i);

		bool ispossible = true;
		for (int i=0; i<N; i++) {
			if (sn[i*2] == sn[i*2+1]) {
				ispossible = false;
				break;
			}
		}
		if (!ispossible) puts("Suspicious bugs found!\n");
		else puts("No suspicious bugs found!\n");
	}
}
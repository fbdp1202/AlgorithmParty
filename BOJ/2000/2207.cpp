// baekjoon 2207 yechan
#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX_N = 10001*2;

int N, M;
int sn[MAX_N], SN, dfsn[MAX_N], dcnt;
vector<int> adj[MAX_N];

bool finished[MAX_N];
stack<int> st;
vector<vector<int>> SCC;

inline int oppo(int n) { return (n%2) ? n-1:n+1; }

int dfs(int here) {
	int ret = dfsn[here] = ++dcnt;
	st.push(here);

	for (int there : adj[here]) {
		if (!dfsn[there]) ret = min(ret, dfs(there));
		else if (!finished[there]) ret = min(ret, dfsn[there]);
	}

	if (dfsn[here] == ret) {
		vector<int> currSCC;
		while (1) {
			int t = st.top();
			st.pop();
			sn[t] = SN;
			finished[t] = true;
			currSCC.push_back(t);
			if (t == here) break;
		}
		SCC.push_back(currSCC);
		SN++;
	}
	return ret;
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u = (u < 0) ? -(u+1)*2 : u*2-1;
		v = (v < 0) ? -(v+1)*2 : v*2-1;
		adj[oppo(u)].push_back(v);
		adj[oppo(v)].push_back(u);
	}

	for (int i=0; i<N*2; i++)
		if (!dfsn[i]) dfs(i);

	for (int i=0; i<N; i++) {
		if (sn[i*2] == sn[i*2+1]) {
			puts("OTL");
			return 0;
		}
	}
	puts("^_^");
	return 0;
}
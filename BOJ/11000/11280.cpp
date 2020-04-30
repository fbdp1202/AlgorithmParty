// baekjoon 11280 yechan
#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=10001*2;

int N, M;
vector<int> adj[MAX_N];
int sn[MAX_N], SN, dfsn[MAX_N], dcnt;
vector<vector<int>> SCC;
bool finished[MAX_N];
stack<int> st;

inline int oppo(int n) { return (n%2) ? n-1 : n + 1; }

int dfs(int here) {
	dfsn[here] = ++dcnt;
	st.push(here);

	int result = dfsn[here];
	for (int there: adj[here]) {
		if (!dfsn[there]) result = min(result, dfs(there));
		else if (!finished[there]) result = min(result, dfsn[there]);
	}

	if (dfsn[here] == result) {
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
	return result;
}

int main() {
	scanf("%d%d", &N, &M);
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
			puts("0");
			return 0;
		}
	}
	puts("1");
	return 0;
}
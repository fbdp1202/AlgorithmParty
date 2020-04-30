// baekjoon 3747 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=1001;
inline int encode(int n) { return (n<0) ? -(n+1)*2:n*2-1; }
inline int oppo(int n) { return (n%2) ? n-1:n+1; }

int N, M;
int dfsn[MAX_N*2], dcnt, sn[MAX_N*2], SN;
bool finished[MAX_N*2];
vector<vector<int>> adj;
stack<int> st;

int dfs(int here) {
	int ret = dfsn[here] = ++dcnt;
	st.push(here);

	for (int there: adj[here]) {
		if (!dfsn[there]) ret = min(ret, dfs(there));
		else if (!finished[there]) ret = min(ret, dfsn[there]);
	}

	if (ret == dfsn[here]) {
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
	while (scanf("%d%d", &N, &M)!=-1) {
		memset(sn, 0, sizeof(sn));
		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, 0, sizeof(finished));
		SN = dcnt = 0;
		adj = vector<vector<int>>(N*2);
		for (int i=0; i<M; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u = encode(u);
			v = encode(v);
			adj[oppo(u)].push_back(v);
			adj[oppo(v)].push_back(u);
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
		puts(ispossible ? "1":"0");
	}
}
// baekjoon 3648 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

const int MAX_N=1001*2;

int N, M;
int dfsn[MAX_N], dcnt, sn[MAX_N], SN;
vector<vector<int>> adj;
vector<vector<int>> SCC;
stack<int> st;
bool finished[MAX_N];
int ans[MAX_N/2];

inline int oppo(int n) { return (n%2) ? n-1:n+1; }
inline int encode(int n) { return (n<0) ? -(n+1)*2:n*2-1; }

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
	while (scanf("%d%d", &N, &M) != -1) {
		adj = vector<vector<int>>(N*2+1);
		SN = dcnt = 0;
		SCC.clear();
		memset(sn, 0, sizeof(sn));
		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, 0, sizeof(finished));
		memset(ans, 0, sizeof(ans));
		for (int i=0; i<M; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u=encode(u);
			v=encode(v);
			adj[oppo(u)].push_back(v);
			adj[oppo(v)].push_back(u);
		}
		adj[oppo(1)].push_back(1);
		
		for (int i=0; i<N*2; i++)
			if (!dfsn[i]) dfs(i);

		bool ispossible = true;
		for (int i=0; i<N; i++) {
			if (sn[i*2] == sn[i*2+1]) {
				ispossible = false;
				break;
			}
		}
		puts(ispossible ? "yes" : "no");
	}
	return 0;
}
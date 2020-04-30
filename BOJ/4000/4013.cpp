// baekjoon 4013 yechan
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int MAX_N = 500001;

int N, M, SN, sn[MAX_N], dfsn[MAX_N], cnt;
bool finished[MAX_N];
vector<int> adj[MAX_N];
vector<vector<int> > SCC;
stack<int> st;

int DFS(int here) {
	dfsn[here] = ++cnt;
	st.push(here);

	int result = dfsn[here];
	for (int next: adj[here]) {
		if (dfsn[next] == 0) result	= min(result, DFS(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	if (dfsn[here] == result) {
		vector<int> currSCC;
		while (1) {
			int t = st.top();
			st.pop();
			sn[t] = SN;
			finished[t] = true;
			currSCC.push_back(t);
			if (here == t) break;
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
		scanf("%d%d". &u, &v);
		u--, v--;
		adj[u].push_back(v);
	}
	return 0;
}
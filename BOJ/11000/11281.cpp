// baekjoon 11281 yechan
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
const int MAX_N=10001*2;

int N, M;
int sn[MAX_N], SN, dfsn[MAX_N], dcnt;
vector<int> adj[MAX_N];
vector<vector<int>> SCC;
stack<int> st;
bool finished[MAX_N];

int number[MAX_N/2];

inline int oppo(int n) { return (n%2) ? n-1 : n+1; }

int dfs(int here){
	dfsn[here] = ++dcnt;
	st.push(here);

	int ret = dfsn[here];
	for (int there: adj[here]) {
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
	memset(number, -1, sizeof(number));
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u = (u < 0) ? -(u+1)*2 : u*2-1;
		v = (v < 0) ? -(v+1)*2 : v*2-1;
		adj[oppo(u)].push_back(v);
		adj[oppo(v)].push_back(u);
	}
	adj[oppo(1)].push_back(1);

	for (int i=0; i<N*2; i++)
		if (!dfsn[i]) dfs(i);

	for (int i=0; i<N; i++) {
		if (sn[i*2] == sn[i*2+1]) {
			puts("0");
			return 0;
		}
	}

	puts("1");
	P p[MAX_N];
	for (int i=0; i<N*2; i++)
		p[i] = P(sn[i], i);

	sort(p, p+N*2);

	for (int i=N*2-1; i>=0; i--) {
		int var = p[i].second;
		if (number[var/2] == -1) number[var/2] = !(var%2);
	}

	for (int i=0; i<N; i++)
		printf("%d ", number[i]);

	return 0;
}
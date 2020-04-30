// baekjoon 16367 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
const int MAX_N=5001*2;

int N, M;
int dfsn[MAX_N], sn[MAX_N], SN, dcnt;
vector<int> adj[MAX_N];
bool finished[MAX_N];
int ans[MAX_N];
stack<int> st;
vector<vector<int>> SCC;

inline int encode(int n, char c) { return (c == 'R') ? -n : n; }

inline int oppo(int n) { return (n%2) ? n-1:n+1; }

void genNode(int u, char uc, int v, char vc) {
	u = encode(u, uc);
	u = (u < 0) ? -(u+1)*2:u*2-1;
	v = encode(v, vc);
	v = (v < 0) ? -(v+1)*2:v*2-1;
	adj[oppo(u)].push_back(v);
	adj[oppo(v)].push_back(u);
}

int dfs(int here) {
	int ret = dfsn[here] = ++dcnt;
	st.push(here);

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
			if (here == t) break;
		}
		SCC.push_back(currSCC);
		SN++;
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int num[3];
		char color[3];
		for (int j=0; j<3; j++)
			scanf("%d %c", &num[j], &color[j]);

		for (int j=0; j<3; j++) {
			for (int k=j+1; k<3; k++) {
				genNode(num[j], color[j], num[k], color[k]);
			}
		}
	}
	
	for (int i=0; i<N*2; i++)
		if (!dfsn[i]) dfs(i);

	for (int i=0; i<N; i++) {
		if (sn[i*2] == sn[i*2+1]) {
			puts("-1");
			return 0;
		}
	}

	P p[MAX_N];
	for (int i=0; i<N*2; i++) {
		p[i] = P(sn[i], i);
	}
	sort(p, p+N*2);

	memset(ans, -1, sizeof(ans));
	for (int i=N*2-1; i>=0; i--) {
		int var = p[i].second;
		if (ans[var/2] == -1) ans[var/2] = !(var%2);
	}

	for (int i=0; i<N; i++) {
		printf("%c", (ans[i]) ? 'B':'R');
	}
	puts("");
	return 0;
}
// baekjoon 15675 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <cstring>

using namespace std;

const int MAX_N=1001;

int N, M;
int dfsn[MAX_N*4], dcnt, sn[MAX_N*4], SN;
vector<int> adj[MAX_N*4];
stack<int> st;
bool finished[MAX_N*4];

char board[MAX_N][MAX_N];

inline int encode(int n) { return (n<0) ? -(n+1)*2:n*2-1; }
inline int oppo(int n) { return (n%2) ? n-1:n+1; }

int dfs(int here) {
	int ret = dfsn[here] = ++dcnt;
	st.push(here);

	for (int there: adj[here]) {
		if (!dfsn[there]) ret = min(ret, dfs(there));
		else if (!finished[there]) ret = min(ret, dfsn[there]);
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
	scanf("%d%d", &N, &M);
	int u, v;
	for (int i=0; i<N; i++) {
		scanf("%s", board[i]);
		for (int j=0; j<M; j++) {
			if (board[i][j] == '*') {
				u = encode(i+M+1);
				v = encode(j+1);
				adj[oppo(u)].push_back(v);
				adj[oppo(v)].push_back(u);
				adj[u].push_back(oppo(v));
				adj[v].push_back(oppo(u));
			}
			if (board[i][j] == '#') {
				u = encode(i+M+1);
				v = encode(j+1);
				adj[oppo(u)].push_back(oppo(v));
				adj[v].push_back(u);
				adj[u].push_back(v);
				adj[oppo(v)].push_back(oppo(u));
			}
		}
	}

	for (int i=0; i<N*2+M*2; i++)
		if (!dfsn[i]) dfs(i);

	for (int i=0; i<N+M; i++) {
		if (sn[i*2] == sn[i*2+1]) {
			puts("0");
			return 0;
		}
	}
	puts("1");
	return 0;
}
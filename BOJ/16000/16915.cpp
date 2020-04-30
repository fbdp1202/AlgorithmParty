// baekjoon 16915 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=100001;

int N, M;
int dfsn[MAX_N*2], dcnt, sn[MAX_N*2], SN;
vector<int> adj[MAX_N*2];
bool finished[MAX_N*2];
stack<int> st;
bool room[MAX_N];
vector<int> sw[MAX_N];

inline int encode(int n) { return (n<0) ? -(n+1)*2:n*2-1; }
inline int oppo(int n) { return (n%2) ? n-1:n+1; }

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
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		scanf("%d", &room[i]);

	for (int i=1; i<=M; i++) {
		int k=0;
		scanf("%d", &k);
		for (int j=0; j<k; j++) {
			int x;
			scanf("%d", &x);
			sw[x].push_back(i);
		}
	}

	for (int i=1; i<=N; i++) {
		int a, b;
		a = encode(sw[i][0]);
		b = encode(sw[i][1]);
		if (!room[i]) {
			adj[oppo(a)].push_back(b);
			adj[oppo(b)].push_back(a);
			adj[a].push_back(oppo(b));
			adj[b].push_back(oppo(a));
		} else {
			adj[oppo(a)].push_back(oppo(b));
			adj[b].push_back(a);
			adj[a].push_back(b);
			adj[oppo(b)].push_back(oppo(a));
		}
	}

	for (int i=0; i<M*2; i++)
		if (!dfsn[i]) dfs(i);

	for (int i=0; i<M; i++) {
		if (sn[i*2] == sn[i*2+1]) {
			puts("0");
			return 0;
		}
	}
	puts("1");
	return 0;
}
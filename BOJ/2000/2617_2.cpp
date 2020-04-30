// baekjoon 2617_2 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, M;
bool uVisited[MAX_N];
vector<int> uAdj[MAX_N];

bool dVisited[MAX_N];
vector<int> dAdj[MAX_N];

int uDFS(int here) {
	int ret = 0;
	for (int &next: uAdj[here]) {
		if (!uVisited[next]) {
			uVisited[next]=true;
			ret += uDFS(next) + 1;
		}
	}
	return ret;
}

int dDFS(int here) {
	int ret = 0;
	for (int &next: dAdj[here]) {
		if (!dVisited[next]) {
			dVisited[next]=true;
			ret += dDFS(next) + 1;
		}
	}
	return ret;
}

int main() {

	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--,v--;
		uAdj[v].push_back(u);
		dAdj[u].push_back(v);
	}

	int up, down;
	int ret = 0;
	for (int i=0; i<N; i++) {
		memset(uVisited, 0, sizeof(uVisited));
		memset(dVisited, 0, sizeof(dVisited));
		up = uDFS(i);
		down = dDFS(i);
		if (up > N/2 || down > N/2) ret++;
	}
	printf("%d\n", ret);
	return 0;
}
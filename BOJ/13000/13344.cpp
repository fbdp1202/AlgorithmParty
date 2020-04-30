// baekjoon 13344 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=50001;
typedef pair<int,int> P;

int N, M;
int root[MAX_N];
vector<int> adj[MAX_N];
vector<P> bigger;
int visited[MAX_N];

int find(int x) {
	if (root[x] < 0) return x;
	return root[x] = find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	root[b] = a;
}

bool findCycle(int here) {
	if (visited[here]) {
		if (visited[here] == -1) return true;
		return false;
	}

	visited[here] = -1;
	for (int i=0; i<adj[here].size(); i++)
		if (findCycle(adj[here][i]))
			return true;

	visited[here] = 1;
	return false;
}

int main() {
	memset(root, -1, sizeof(root));
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int K, L;
		char c;
		scanf("%d %c %d", &K, &c, &L);
		if (c == '=') merge(K, L);
		else bigger.push_back(P(K, L));
	}

	for (int i=0; i<bigger.size(); i++) {
		int x = find(bigger[i].first);
		int y = find(bigger[i].second);
		adj[x].push_back(y);
	}

	for (int i=0; i<N; i++) {
		if (findCycle(i)) {
			puts("inconsistent");
			return 0;
		}
	}
	puts("consistent");
	return 0;
}
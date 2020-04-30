// baekjoon 4792 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int N, M, K;
int root[MAX_N];
pair<int,pair<int,int> > node[MAX_N*MAX_N];

int find(int x) {
	if (!root[x]) return x;
	return root[x] = find(root[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main() {
	while (1) {
		scanf("%d%d%d", &N, &M, &K);
		if (!N && !M && !K) break;
		for (int i=0; i<M; i++) {
			char c;
			int u, v;
			scanf(" %c%d%d", &c, &u, &v);
			node[i] = make_pair(c=='R'? 0 : 1, make_pair(u, v));
		}
		sort(node, node+M);

		int minK = 0;
		int numNode = 0;
		memset(root, 0, sizeof(root));
		for (int i=0; i<M; i++) {
			int a = node[i].second.first;
			int b = node[i].second.second;
			int c = node[i].first;
			if (merge(a, b)) {
				minK += c;
				numNode++;
			}
		}

		int maxK = 0;
		numNode = 0;
		memset(root, 0, sizeof(root));
		for (int i=M-1; i>=0; i--) {
			int a = node[i].second.first;
			int b = node[i].second.second;
			int c = node[i].first;
			if (merge(a, b)) {
				maxK += c;
				numNode++;
			}
		}
		if (numNode == N-1 && minK <= K && K <= maxK) puts("1");
		else puts("0");
	}
	return 0;
}
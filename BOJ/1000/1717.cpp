// baekjoon 1717 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 1000001;

int N, M, cmd, a, b;
int root[MAX_N];

int find(int x) {
	if (root[x] == -1) return x;
	return root[x] = find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	root[a] = b;
}

int main() {
	memset(root, -1, sizeof(root));

	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd) {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		} else {
			merge(a, b);
		}
	}
	return 0;
}
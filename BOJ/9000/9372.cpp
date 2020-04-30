// baekjoon 9372 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 1001

int T, N, M, u, v, root[MAX_N];

int find(int n) {
	if (root[n]<0) return n;
	return root[n] = find(root[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		memset(root, -1, sizeof(root));
		int cnt = 0;
		for (int i=0; i<M; i++) {
			scanf("%d%d", &u, &v);
			if (merge(u, v)) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
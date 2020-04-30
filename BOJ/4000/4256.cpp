// baekjoon 4256 reference
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define MAX_N 1000

int T, N, pre[MAX_N];
map<int, int> mt;


void postorder(int s, int e, int x, int y) {
	if (s > e || x > y) return;

	int root = pre[s];
	int pos = mt[root];

	postorder(s+1, s+(pos-x), x, pos -1);
	postorder(s+(pos-x)+1, e, pos + 1, y);
	printf("%d ", root);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		mt.clear();
		for (int i=0; i<N; i++) scanf("%d", &pre[i]);
		for (int i=0; i<N; i++){
			int x; scanf("%d", &x);
			mt[x] = i;
		}
		postorder(0, N-1, 0, N-1); puts("");
	}
	return 0;
}
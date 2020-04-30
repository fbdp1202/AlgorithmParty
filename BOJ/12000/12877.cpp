// baekjoon 12877 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=50001;
const int MAX_K=100001;

int N, K;
int root[MAX_N];

int find(int x) {
	if (!root[x]) return x;
	return root[x]=find(root[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<K; i++) {
		int cmd, a, b; 
		scanf("%d%d%d",)
	}
	return 0;
}
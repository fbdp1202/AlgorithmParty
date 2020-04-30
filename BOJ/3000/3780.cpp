// baekjoon 3780 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 20000
#define MOD_NUM 1000
char ch;
int T, N, a, b, parent[MAX_N+1], dist[MAX_N+1];

int find(int x) {
	if (parent[x] == x) return x;
	int tmp = find(parent[x]);
	dist[x] += dist[parent[x]];
	parent[x] = tmp;
	return tmp;
}

void merge(int x, int y) {
	dist[x] = abs(x-y) % MOD_NUM;
	parent[x] = y;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for(int i=0; i<=N; i++) parent[i] = i;
		fill(dist, dist+MAX_N+1, 0);
		while (1) {
			scanf(" %c", &ch);
			if (ch == 'E') {
				scanf("%d", &a);
				find(a);
				printf("%d\n", dist[a]);
			}
			else if (ch == 'I') {
				scanf("%d %d", &a, &b);
				merge(a, b);
			}
			else 
				break;
		}
	}
	return 0;
}
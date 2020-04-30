// baekjoon 1613 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=501;
int N, K;
bool adj[MAX_N][MAX_N];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=0; i<K; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u][v]=true;
	}

	for (int k=1; k<=N; k++) {
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=N; j++) {
				if (i == j || i == k || j == k) continue;
				adj[i][j] |= adj[i][k] && adj[k][j];
			}
		}
	}

	int S;
	scanf("%d", &S);
	for (int i=0; i<S; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (adj[a][b]) puts("-1");
		else if (adj[b][a]) puts("1");
		else puts("0");
	}

	return 0;
}
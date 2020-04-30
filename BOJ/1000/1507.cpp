// baekjoon 1507 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=21;

int N, adj[MAX_N][MAX_N], connect[MAX_N][MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &adj[i][j]);

	for (int k=0; k<N; k++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (i == j || i == k || k == j) continue;
				if (adj[i][j] == (adj[i][k] + adj[k][j])) connect[i][j] = connect[j][i] = 1;
				if (adj[i][j] > adj[i][k] + adj[k][j]) return !printf("-1\n");
			}
		}
	}

	int ret = 0;
	for (int i=0; i<N; i++)
		for (int j=i+1; j<N; j++)
			if (!connect[i][j])
				ret += adj[i][j];

	printf("%d\n", ret);
	return 0;
}
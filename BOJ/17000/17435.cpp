// baekjoon 17435 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_M=200001;
const int MAX_K=19;

int M;
int f[MAX_M];
int parent[MAX_M][MAX_K];

int main() {
	memset(parent, -1, sizeof(parent));

	scanf("%d", &M);
	for (int i=1; i<=M; i++) {
		scanf("%d", &f[i]);
		parent[i][0] = f[i];
	}

	for (int j=0; j<MAX_K-1; j++) {
		for (int i=1; i<=M; i++) {
			parent[i][j+1] = parent[parent[i][j]][j];
		}
	}

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int N, x;
		scanf("%d%d", &N, &x);

		for (int i=0; N; i++) {
			if (N % 2) x = parent[x][i];
			N/=2;
		}
		printf("%d\n", x);
	}
	return 0;
}
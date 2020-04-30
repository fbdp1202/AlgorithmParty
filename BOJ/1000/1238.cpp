// baekjoon 1238 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX_N = 1001;
const int MAX_M = 10001;

int N, M, X;
int graph[MAX_N][MAX_N];
int a, b, c;

int main(void) {
	scanf("%d %d %d", &N, &M, &X);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			graph[i][j] = INF;
			if (i == j) graph[i][j]=0;
		}
	}

	for (int i=0; i<M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a-1][b-1] = min(graph[a-1][b-1], c);
	}

	for (int k=0; k<N; k++)
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);

	int maxV = 0;
	for (int i=0; i<N; i++)
		maxV = max(maxV, graph[i][X-1]+graph[X-1][i]);
	printf("%d\n", maxV);
}
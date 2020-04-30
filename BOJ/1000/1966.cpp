// baekjoon 1966 yechan
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 101

int T, N, M, data[MAX_N];
bool visited[MAX_N];

int main() {
	scanf("%d", &T);
	while (T--) {
		fill(visited, visited+MAX_N, false);
		scanf("%d %d", &N, &M);
		for (int i=0; i<N; i++) scanf("%d", &data[i]);

		int prevIdx=0;
		for (int i=1; i<=N; i++) {
			int maxIdx = 0, maxWeight = INT_MIN;
			for (int j=prevIdx; j<N+prevIdx; j++) {
				int now = j%N;
				if (!visited[now]) {
					if (maxWeight < data[now]) {
						maxWeight = data[now];
						maxIdx=now;
					}
				}
			}
			visited[maxIdx]=true;

			if (maxIdx == M) {
				printf("%d\n", i); break;
			}
			prevIdx=maxIdx+1;
		}
	}
	return 0;
}
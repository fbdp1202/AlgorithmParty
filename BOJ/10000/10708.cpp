// baekjoon 10708 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 101
int N, M, target[MAX_N], score[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++)
		scanf("%d", &target[i]);

	for (int i=0; i<M; i++) {
		int cnt = 0;
		for (int j=1; j<=N; j++) {
			int x; scanf(" %d", &x);
			if (target[i] == x) score[j]++;
			else cnt++;
		}
		score[target[i]] += cnt;
	}
	for (int i=1; i<=N; i++)
		printf("%d\n", score[i]);
	return 0;
}
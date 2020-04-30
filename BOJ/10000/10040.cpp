// baekjoon 10040 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1000;
int N, M, X, maxV, maxIdx, vote[MAX_N], score[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%d", &score[i]);

	for (int i=0; i<M; i++) {
		scanf("%d", &X);
		for (int j=0; j<N; j++) {
			if (score[j] <= X) {
				vote[j]++;
				if (maxV < vote[j]) {
					maxV = vote[j];
					maxIdx=j+1;
				}
				break;
			}
		}
	}
	printf("%d\n", maxIdx);
	return 0;
}
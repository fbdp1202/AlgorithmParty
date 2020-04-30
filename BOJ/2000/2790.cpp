// baekjoon 2790 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=300001;
int N;
int score[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &score[i]);
	sort(score, score+N);

	int ret = 1;
	int maxV = 0;
	for (int i=N-2; i>=0; i--) {
		maxV = max(score[i+1] + (N-1-i), maxV);
		if (maxV <= score[i] + N) ret++;
		else break;
	}
	printf("%d\n",ret);
	return 0;
}
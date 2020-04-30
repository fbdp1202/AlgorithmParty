// baekjoon 2643 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, dp[MAX_N], ret;
pair<int, int> paper[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &paper[i].first, &paper[i].second);
		if (paper[i].first > paper[i].second)
			swap(paper[i].first, paper[i].second);
	}
	sort(paper, paper+N);

	for (int i=0; i<N; i++)
		for (int j=i+1; j<N; j++)
			if (paper[i].first <= paper[j].second && paper[i].second <= paper[j].second)
				dp[j] = max(dp[i]+1, dp[j]);

	for (int i=0; i<N; i++)
		ret = max(dp[i], ret);
	printf("%d\n", ret+1);
	return 0;
}
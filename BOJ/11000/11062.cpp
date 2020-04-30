// baekjoon 11062 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=1001;
const int MIN_INF=-2e9;

int T, N, data[MAX_N], dp[2][MAX_N][MAX_N];

void game(int here, int left, int right) {
	if (left == right) {
		dp[here][left][right] = data[left];
		dp[here^1][left][right] = 0;
		return;
	}

	int &ret1 = dp[here][left][right];
	int &ret2 = dp[here ^ 1][left][right];

	if (ret1 != MIN_INF) return;

	// choose left
	game(here^1, left+1, right);
	if (ret1 < data[left] + dp[here][left+1][right]) {
		ret1 = data[left] + dp[here][left+1][right];
		ret2 = dp[here^1][left+1][right];
	}

	// choose right
	game(here^1, left, right-1);
	if (ret1 < data[right] + dp[here][left][right-1]) {
		ret1 = data[right] + dp[here][left][right-1];
		ret2 = dp[here^1][left][right-1];
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			fill(dp[0][i], dp[0][i]+N, MIN_INF);
			fill(dp[1][i], dp[1][i]+N, MIN_INF);
		}
		for (int i=0; i<N; i++)
			scanf("%d", &data[i]);

		game(0, 0, N-1);
		printf("%d\n", dp[0][0][N-1]);
	}
	return 0;
}

// #include<cstdio>
// #include<algorithm>

// using namespace std;

// int T, N, c[1001];

// int main() {
// 	scanf("%d", &T);
// 	while (T--) {
// 		int dp[1001] = { 0 };
// 		scanf("%d", &N);
// 		for (int i = 1; i <= N; i++) scanf("%d", &c[i]), c[i] += c[i - 1];
// 		for (int i = 1; i <= N; i++) for (int j = N; j >= i; j--) dp[j] = c[j] - c[j - i] - min(dp[j], dp[j - 1]);
// 		printf("%d\n", dp[N]);
// 	}
// 	return 0;
// }
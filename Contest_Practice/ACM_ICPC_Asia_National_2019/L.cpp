#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=250;
const int MAX_TIME = 250*250+1;
const int MAX_INF = 1e9;
typedef pair<int, int> P;

int N;
int dp[2][MAX_TIME];
P data[MAX_N];

int solve() {
	for (int i=0; i<MAX_TIME; i++)
		dp[0][i] = MAX_INF;

	dp[0][data[0].first] = 0;
	dp[0][0] = data[0].second;


	for (int i=1; i<N; i++) {
		int npos = i%2, cpos = (i+1)%2;
		int a = data[i].first;
		int b = data[i].second;
		for (int j=0; j<MAX_TIME; j++)
			dp[npos][j]=MAX_INF;

		for (int j=MAX_TIME-1; j>=0; j--) {
			if (dp[cpos][j] != MAX_INF) {
				dp[npos][j+a] = min(dp[npos][j+a], dp[cpos][j]);
				dp[npos][j] = min(dp[npos][j], dp[cpos][j]+b);
			}
		}
	}

	int ret = MAX_INF;
	int pos = (N+1)%2;
	for (int i=0; i<MAX_TIME; i++)
		ret = min(ret, max(i, dp[pos][i]));

	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &data[i].first, &data[i].second);

	printf("%d\n", solve());
	return 0;
}
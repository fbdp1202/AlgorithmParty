// baekjoon 2612 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
const int MIN_INF=-1e9;

int N, M, a1pos, a2pos;
char s1[MAX_N], s2[MAX_N];
char a1[MAX_N], a2[MAX_N];
int dp[MAX_N][MAX_N];

int dfs(int n, int m) {
	if (n == N && m == M) return 0;
	int &ret = dp[n][m];
	if (ret != MIN_INF) return ret;
	ret = 0;
	if (s1[n] && (s1[n] == s2[m])) ret = max(ret, dfs(n+1, m+1)+3);
	if (s2[m]) ret = max(ret, dfs(n, m+1)-2);
	if (s1[n]) ret = max(ret, dfs(n+1, m)-2);
	return ret;
}

void tracking(int n, int m) {
	if (!dp[n][m]) return;

	if (s1[n] == s2[m]) {
		a1[a1pos++] = s1[n];
		a2[a2pos++] = s2[m];
		tracking(n+1, m+1);
	} else {
		if (dp[n][m] == dp[n][m+1] - 2) {
			a2[a2pos++] = s2[m];
			tracking(n, m+1);
		} else if (dp[n][m] == dp[n+1][m] - 2) {
			a1[a1pos++] = s1[n];
			tracking(n+1, m);
		} else if (dp[n][m] == dp[n+1][m+1] - 2) {
			a1[a1pos++] = s1[n];
			a2[a2pos++] = s2[m];
			tracking(n+1,m+1);
		}
	}
}

int main() {
	scanf("%d %s %d %s", &N, s1, &M, s2);
	for (int i=0; i<=N; i++)
		for (int j=0; j<=M; j++)
			dp[i][j] = MIN_INF;

	printf("%d\n", dfs(0,0));
	if (dp[0][0]) {
		tracking(0,0);
		a1[a1pos]='\0';
		a2[a2pos]='\0';
		printf("%s\n%s\n",a1,a2);
	}
	return 0;
}
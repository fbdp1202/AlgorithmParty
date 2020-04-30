// baekjoon 1514 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;
const int MAX_INF=1e9;

int N;
int dp[MAX_N][10][10][10][2];
char A[MAX_N], B[MAX_N];

int dfs(int here, int one, int two, int three, int w) {
	if (here == N) return 0;
	int &ret = dp[here][one][two][three][w];
	if (ret != -1) return ret;
	ret = MAX_INF;
	int curr = (A[here]-'0'+one)%10;
	int dest = (B[here]-'0');
	if (curr == dest) return ret=min(dfs(here+1, two, three, 0, 0), dfs(here+1, two, three, 0, 1));

	for (int i=1; i<=3; i++) {
		if (w) {
			ret=min(ret, dfs(here, (one+i)%10, two, three, w)+1);
			ret=min(ret, dfs(here, (one+i)%10, (two+i)%10, three, w)+1);
			ret=min(ret, dfs(here, (one+i)%10, (two+i)%10, (three+i)%10, w)+1);
		} else {
			ret=min(ret, dfs(here, (10+one-i)%10, two, three, w)+1);
			ret=min(ret, dfs(here, (10+one-i)%10, (10+two-i)%10, three, w)+1);
			ret=min(ret, dfs(here, (10+one-i)%10, (10+two-i)%10, (10+three-i)%10, w)+1);
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	scanf("%s%s", A, B);
	printf("%d\n", min(dfs(0,0,0,0,0),dfs(0,0,0,0,1)));
	return 0;
}
// baekjoon 15483 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_L=1111;
const int MAX_INF=1e9;

char A[MAX_L], B[MAX_L];
int dp[MAX_L][MAX_L];

int dfs(int apos, int bpos) {
	// end point
	if (!A[apos] && !B[bpos]) return 0;
	// insert A
	if (!A[apos]) return dfs(apos, bpos+1)+1;
	// delete A
	if (!B[bpos]) return dfs(apos+1, bpos)+1;
	int &ret = dp[apos][bpos];
	if (ret != -1) return ret;
	ret = MAX_INF;
	if (A[apos] == B[bpos]) ret = min(ret, dfs(apos+1, bpos+1));
	// insert A
	ret = min(ret, dfs(apos, bpos+1)+1);
	// delete A
	ret = min(ret, dfs(apos+1, bpos)+1);
	// change A
	ret = min(ret, dfs(apos+1, bpos+1)+1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s%s", A,B);
	printf("%d\n", dfs(0,0));
	return 0;
}
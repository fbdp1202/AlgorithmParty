// baekjoon 9023 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;
const int MAX_INF=1e9;

int T;
int N, C, D, d;
int A[MAX_N], B[MAX_N];
int Alen, Blen;

int dp[MAX_N][MAX_N][3][3];

int dfs(int pA, int pB, int rU, int rD) {
	if (pA == Alen && pB == Blen) return 0;

	int &ret = dp[pA][pB][rU][rD];
	if (ret != -1) return ret;

	ret = MAX_INF;
	int cost;
	if (pA != Alen && pB != Blen) {
		cost = ((A[pA] == B[pB]) ? C : C+C);
		ret = min(ret, dfs(pA+1, pB+1, 1, 1) + cost);
	}
	if (pB != Blen) { // A Team rest
		cost = C + d + ((rU == 2) ? 0 : D);
		ret = min(ret, dfs(pA, pB+1, 2, 1) + cost);
	}
	if (pA != Alen) { // B Team rest
		cost = C + d + ((rD == 2) ? 0 : D);
		ret = min(ret, dfs(pA+1, pB, 1, 2) + cost);
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &C, &D, &d);
		int pos = 0;
		while (1) {
			scanf("%d", &A[pos]);
			if (!A[pos]) break;
			pos++;
		}
		Alen = pos;
		pos = 0;
		while (1) {
			scanf("%d", &B[pos]);
			if (!B[pos]) break;
			pos++;
		}
		Blen = pos;
		printf("%d\n", dfs(0,0,0,0));
	}
	return 0;
}
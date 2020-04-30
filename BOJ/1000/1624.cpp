// baekjoon 1624 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;
const int MAX_V=2001;
const int MAX_INF=1e9;

int N, A[MAX_N];
int dp[MAX_N];
vector<int> xpos;

bool check(int a, int b) {
	if (b - a < 2) return true;
	a = xpos[a]; b = xpos[b];
	int s = MAX_INF, e = -MAX_INF;
	for (int i=0; i<N; i++) {
		if (a > A[i] || b < A[i]) continue;
		if (s < A[i] && A[i] < e) return false;
		s = min(s, A[i]);
		e = max(e, A[i]);
	}
	return true;
}

int main() {
	fill(dp, dp+MAX_N, MAX_INF);

	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &A[i]);
		xpos.push_back(A[i]);
	}
	xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
	sort(xpos.begin(), xpos.end());

	int xsize = xpos.size();

	for (int i=0; i<xsize; i++) {
		if (check(0, i)) {
			dp[i]=1;
			continue;
		}
		for (int j=i; j>0; j--) {
			if (!check(j,i)) break;
			dp[i] = min(dp[i], dp[j-1] + 1);
		}
	}

	printf("%d\n", dp[xsize-1]);
	return 0;
}
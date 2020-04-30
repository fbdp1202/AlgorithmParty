// baekjoon 1315 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;
const int MAX_S=1001;
const int MAX_I=1001;

struct Quest{
	int s, i, p;
	Quest():Quest(0,0,0){}
	Quest(int s1, int i1, int p1):s(s1),i(i1),p(p1){}
	int done(int s1, int i1) {
		return ((s1 >= s) || (i1 >= i)) ? p:0;
	}
};

int N;
int dp[MAX_S][MAX_I];
Quest quest[MAX_N];

int dfs(int s, int i) {
	int &ret = dp[s][i];
	if (ret != -1) return ret;

	ret = 0;
	int p = 0;
	for (int j=0; j<N; j++) {
		int tmp = quest[j].done(s,i);
		if (tmp) ret++;
		p += tmp;
	}
	if (ret == N) return ret;
	p -= (s+i-2);
	for (int j=0; j<=p && p; j++)
		ret = max(ret, dfs(min(1000,s+j),min(1000,i+p-j)));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int j=0; j<N; j++) {
		int s, i, p;
		scanf("%d%d%d", &s, &i, &p);
		quest[j] = Quest(s, i, p);
	}
	printf("%d\n", dfs(1,1));
	return 0;
}
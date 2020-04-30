// baekjoon 2259 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<double,double>;
using PP = pair<int,P>;

#define SQ(x) ((x)*(x))

const int MAX_N=6667;

int N;
double S;
PP mole[MAX_N];
int dp[MAX_N];

int getTime(double x1, double y1, double x2, double y2) {
	return (int)(ceil(sqrt(SQ(x1-x2)+SQ(y1-y2))/S));
}

int getTime(P &a, P &b) {
	return (int)(getTime(a.first, a.second, b.first, b.second));
}

bool ispossible(int a, int b) {
	return (mole[a].first + getTime(mole[a].second, mole[b].second) <= mole[b].first);
}

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=here+1; i<=N; i++)
		if (ispossible(here, i))
			ret = max(ret, dfs(i)+1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%lf", &N, &S);
	for (int i=1; i<=N; i++)
		scanf("%lf%lf%d", &mole[i].second.first, &mole[i].second.second, &mole[i].first);
	sort(mole+1, mole+N+1);
	printf("%d\n", dfs(0));
	return 0;
}
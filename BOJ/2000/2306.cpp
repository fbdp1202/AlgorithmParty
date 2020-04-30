// baekjoon 2306 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=501;

int N;
int dp[MAX_N][MAX_N]; // (left, right)
int fdp[MAX_N][MAX_N];
char str[MAX_N];

bool match(char a, char b) { return ((a == 'a') && (b == 't')) || ((a == 'g') && (b == 'c')); }

int dfs(int l, int r) {
	if (l >= r) return 0; // 글자 불가능
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	if (match(str[l], str[r])) ret = max(ret, dfs(l+1, r-1) + 1);
	ret = max(ret, dfs(l, r-1));
	ret = max(ret, dfs(l+1, r));
	for (int i=l+1; i<r; i++)
		ret = max(ret, dfs(l,i) + dfs(i+1, r));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s", str);
	int N = strlen(str);
	printf("%d\n", dfs(0, N-1)*2);
	return 0;
}
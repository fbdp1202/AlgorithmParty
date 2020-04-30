// baekjoon 1796 yechan
#include <bits/stdc++.h>
using namespace std;
// using P = pair<int,int>;

const int MAX_N=1001;
const int MAX_INF=1e9;

int N;
char str[MAX_N];
int dp[MAX_N][MAX_N][2];
int Lpos[26], Rpos[26];

int dfs(int pos, int L, int R, int T) {
	if (pos == 26) return 0;
	if (Lpos[pos] == MAX_INF) return dfs(pos+1, -1, -1, T);
	if (L == -1 && R == -1) {
		int ret = MAX_INF;
		for (int i=0; i<N; i++)
			if (str[i] - 'a' == pos) ret = min(ret, dfs(pos, i, i, 0) + abs(T-i) + 1);
		return ret;
	}

	int &ret = dp[L][R][T];
	if (ret != -1) return ret;

	ret = MAX_INF;
	int curr = (T == 0) ? L : R;
	if (Lpos[pos] == L && Rpos[pos] == R) return ret = dfs(pos+1, -1, -1, curr);


	if (Lpos[pos] != L) {
		for (int i=L-1; i>=0; i--) {
			if (str[i] - 'a' == pos) {
				ret = min(ret, dfs(pos, i, R, 0) + abs(curr - i) + 1);
				break;
			}
		}
	}

	if (Rpos[pos] != R) {
		for (int i=R+1; i<N; i++) {
			if (str[i] - 'a' == pos) {
				ret = min(ret, dfs(pos, L, i, 1) + abs(i - curr) + 1);
				break;
			}
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s", str);
	N = (int)strlen(str);
	for (int i=0; i<26; i++) {
		Lpos[i] = MAX_INF;
		Rpos[i] = -1;
	}
	for (int i=0; i<N; i++) {
		Lpos[str[i]-'a'] = min(Lpos[str[i]-'a'], i);
		Rpos[str[i]-'a'] = max(Rpos[str[i]-'a'], i);
	}
	printf("%d\n", dfs(0, -1, -1, 0));
	return 0;
}
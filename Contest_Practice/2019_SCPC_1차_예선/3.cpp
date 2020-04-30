#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int T;
ll dp[10001];

ll dfs(int here) {
	ll &ret = dp[here];
	if (ret) return ret;
	ret = 1e9;
	for (int i=1; i<here; i++) {
		ret = min(ret, dp[i]+dp[here-i]);
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	int cnt = 1;
	while ((cnt*(cnt+1))/2 <= 10001) {
		dp[(cnt*(cnt+1))/2] = cnt;
		cnt++;
	}

	for (int t=1; t<=10001; t++) {
		
	}
	return 0;
}
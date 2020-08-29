#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1500051;
int N, dp[MAX_N];

int main() {
	scanf("%d", &N);

	int ret = 0;
	for (int i=0; i<N; i++) {
		int T, P;
		scanf("%d%d", &T, &P);
		dp[i+T] = max(dp[i+T], ret+P);
		ret = max(ret, dp[i+1]);
	}
	printf("%d\n", ret);
	return 0;
}
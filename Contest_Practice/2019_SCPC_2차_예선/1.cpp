#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=30001;

int T, A, B, dp[MAX_N];
bool visited[MAX_N];

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = !visited[here];

	if(here >= 10000 && !visited[here%10000]) {
		ret = max(ret, dfs(here%10000) + !visited[here]);
	}
	if (here >= 1000 && !visited[(here/10000)*1000+here%1000]) {
		ret = max(ret, dfs((here/10000)*1000+here%1000) + !visited[here]);
	}
	if (here >= 100 && !visited[(here/1000)*100+here%100]) {
		ret = max(ret, dfs((here/1000)*100+here%100) + !visited[here]);
	}
	if (here >= 10 && !visited[(here/100)*10+here%10]) {
		ret = max(ret, dfs((here/100)*10+here%10) + !visited[here]);
	}
	if (!visited[here/10]) {
		ret = max(ret, dfs(here/10)+!visited[here]);
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0]=dp[1]=0;
	visited[0]=visited[1]=true;
	for (int i=2; i*i<MAX_N; i++) {
		if (!visited[i]) {
			for (int j=i*i; j<MAX_N; j+=i) {
				visited[j]=true;
			}
		}
	}
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		printf("Case #%d\n", i);
		scanf("%d%d", &A, &B);
		int Acnt = dfs(A);
		int Bcnt = dfs(B);
		if (Acnt == Bcnt) 
			printf("3\n");
		else if (Acnt > Bcnt)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}
// baekjoon 11055 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;
const int MAX_K=1000001;

int N;
int A[MAX_N];
int dp[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);

	for (int i=0; i<N; i++)
		for (int j=A[i]-1; j>=0; j--)
			dp[A[i]] = max(dp[A[i]], dp[j]+A[i]);

	int ret = 0;
	for (int i=0; i<MAX_N; i++)
		ret = max(ret, dp[i]);
	printf("%d\n", ret);
	return 0;
}
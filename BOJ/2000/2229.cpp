// baekjoon 2229 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=1001;

int N, data[MAX_N], dp[MAX_N][MAX_N], maxV, minV;

int backtrack(int start, int end) {
	int &ret=dp[start][end];
	if (ret!=-1) return ret;
	maxV=minV=data[start];
	for (int i=start; i<=end; i++) {
		maxV=max(maxV, data[i]);
		minV=min(minV, data[i]);
	}
	ret=maxV-minV;
	for (int k=start; k<end; k++)
		ret=max(ret,backtrack(start,k)+backtrack(k+1,end));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	printf("%d\n", backtrack(0, N-1));
	return 0;
}
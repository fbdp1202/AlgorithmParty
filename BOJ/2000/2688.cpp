// baekjoon 2688 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const int MAX_N=64;
int T, N;
ll dp[MAX_N];
ll nums[10];
ll pv[10];

int main() {
	for (int i=0; i<10; i++) 
		nums[i]=1;

	for (int i=0; i<64; i++) {
		for (int j=0; j<10; j++)
			dp[i]+=nums[j], pv[j]=nums[j];
		for (int j=0; j<10; j++)
			for (int k=j+1; k<10; k++)
				nums[j]+=pv[k];
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%llu\n", dp[N-1]);
	}
	return 0;
}
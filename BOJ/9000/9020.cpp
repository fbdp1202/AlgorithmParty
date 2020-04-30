// baekjoon 9020 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10001
int T, n, df;
bool prime[MAX_N];

int main() {
	for (int i=2; i<MAX_N; i++) {
		if (prime[i]) continue;
		for (int j=i+i; j<MAX_N; j+=i) {
			prime[j]=true;
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		df=0; n/=2;
		while(1) {
			if(!prime[n-df] && !prime[n+df]) break;
			df++;
		}
		printf("%d %d\n", n-df, n+df);
	}
	return 0;
}
// baekjoon 1788 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll DIV_NUM = 1000000000;

ll N, ret;

int main() {
	scanf("%lld", &N);
	ll prev1=0, prev2=1;
	if (N==0) {
		ret=0;
		printf("0\n");
	}
	else if (N==1) {
		ret=1;
		printf("1\n");
	}
	else if (N < 0) {
		for (int i=-1; i>=N; i--) {
			swap(prev1, prev2);
			prev1-=prev2;
			prev1%=DIV_NUM;
		}
		if (prev1 < 0) printf("-1\n");
		else if (prev1 > 0) printf("1\n");
		else {
			if (prev2 < 0) printf("1\n");
			else printf("-1\n");
		}
		ret=abs(prev1);
	} else {
		printf("1\n");
		for (int i=2; i<=N; i++) {
			swap(prev1, prev2);
			prev2+=prev1;
			prev2%=DIV_NUM;
		}
		ret=prev2;
	}
	printf("%lld\n", ret);
	return 0;
}
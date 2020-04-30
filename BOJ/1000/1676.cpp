// baekjoon 1676 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, result=0;

int main() {
	scanf("%d", &N);
	int tmp2 = 0, tmp5 = 0;

	for (int i=1; i<=N; i++) {
		int tmp = i;
		while (tmp % 10 == 0) {
			tmp /= 10;
			result++;
		}
		while (tmp % 2 == 0) {
			tmp /= 2;
			tmp2++;
		}
		while (tmp % 5 == 0) {
			tmp /= 5;
			tmp5++;
		}
	}
	result += min(tmp2, tmp5);
	printf("%lld\n", result);
	return 0;
}
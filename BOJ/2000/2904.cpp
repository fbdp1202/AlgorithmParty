// baekjoon 2904 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX_N = 1000001;

int N, maxV, data[100], primeNum[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);

	for (int i=0; i<N; i++) {
		int x = data[i];
		maxV = max(maxV, data[i]);
		for (int j=2; j<=x; j++) {
			while (x % j == 0) {
				x /= j;
				primeNum[j]++;
			}
		}
	}

	int moveCnt = 0;
	for (int i=0; i<N; i++) {
		int x = data[i];
		for (int j=2; j<=maxV; j++) {
			int cnt = 0;
			while (x % j == 0) {
				x /= j;
				cnt++;
			}
			moveCnt += max(0, primeNum[j]/N - cnt);
		}
	}

	long long sum = 1;
	for (int i=2; i<=maxV; i++) {
		for (int k=0; k<primeNum[i]/N; k++) {
			sum *= i*1LL;
		}
	}

	printf("%lld %d\n", sum, moveCnt);
	return 0;
}
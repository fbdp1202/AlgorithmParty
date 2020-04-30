// baekjoon 10211 yechan
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int T, N, X, result, tmp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		scanf("%d", &X);
		result = X; tmp = X; N--;
		while (N--){
			scanf("%d", &X);
			if (tmp >= 0) tmp += X;
			if (tmp < 0) tmp = X;
			result = max(result, tmp);
		}
		printf("%d\n", result);
	}
	return 0;
}
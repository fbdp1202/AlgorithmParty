// baekjoon 5565 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, sum;

int main() {
	scanf("%d", &N);
	for (int i=0; i<9; i++) {
		int x; scanf("%d", &x);
		sum +=x;
	}
	printf("%d\n", N-sum);
	return 0;
}
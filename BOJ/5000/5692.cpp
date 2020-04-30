// baekjoon 5692 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int fact[9];

int N;

int main() {
	fact[0]=1;
	for (int i=1; i<9; i++)
		fact[i] = fact[i-1]*i;

	while (1) {
		scanf("%d", &N);
		if (!N) break;
		int ret = 0;
		for (int i=1; N; i++) {
			ret += fact[i]*(N%10);
			N/=10;
		}

		printf("%d\n", ret);
	}
}
// baekjoon 1940 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
int N, M, x, number[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	int ret=0;
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		number[x]++;
	}

	for (int i=1; i<(M+1)/2 && i<MAX_N; i++) {
		if (M-i < MAX_N) ret += min(number[i], number[M-i]);
		number[i]=0;
	}
	if (M%2==0 && (M/2)<MAX_N) ret += number[M/2]/2;
	printf("%d\n", ret);
	return 0;
}
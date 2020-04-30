// baekjoon 11004 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K, A[5000000];

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) 
		scanf("%d", &A[i]);
	sort(A, A+N);

	printf("%d", A[K-1]);
	return 0;
}
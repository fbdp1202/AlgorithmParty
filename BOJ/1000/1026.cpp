// baekjoon 1026 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 50

int N, result, A[MAX_N], B[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);
	for (int i=0; i<N; i++)
		scanf("%d", &B[i]);
	sort(A, A+N);
	sort(B, B+N);

	for (int i=0; i<N; i++) {
		result += A[N-1-i]*B[i];
	}
	printf("%d", result);
	return 0;
}
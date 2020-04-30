// baekjoon 1377 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=500001;
int N, A[MAX_N], B[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &A[i]);
		B[i]=A[i];
	}
	sort(A, A+N);
	int Apos=0, Bpos=0;

	while (Apos < N && Bpos < N) {
		if (A[Apos] == B[Bpos]) Apos++;
		Bpos++;
	}
	printf("%d\n", A[Apos-1]);
	return 0;
}
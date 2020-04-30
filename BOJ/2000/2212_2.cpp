// baekjoon 2212_2 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;
int N, K, arr[MAX_N], A[MAX_N], ret;

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+N);
	for (int i=0; i<N-1; i++)
		A[i] = arr[i+1] - arr[i];
	sort(A, A+N-1);
	for (int i=0; i<N-K; i++)
		ret += A[i];
	printf("%d\n", ret);
	return 0;
}
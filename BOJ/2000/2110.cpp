// baekjoon 2110 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=200001;

int N, C, A[MAX_N];

bool check(int here) {
	int count = 1;
	int pv = A[0];
	for (int i=1; i<N; i++) {
		if (A[i] - pv >= here) {
			count++;
			pv = A[i];
		}
	}
	return count >= C;
}

int main() {
	scanf("%d%d", &N, &C);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);
	sort(A, A+N);

	int left=1, right=1e9;
	int ret=0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			left = mid + 1;
			ret = max(ret, mid);
		} else {
			right = mid - 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}
// baekjoon 2512 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;

int N, M, money[MAX_N];

bool check(int here) {
	int sum = 0;
	for (int i=0; i<N; i++)
		sum += min(money[i], here);
	return sum <= M;
}

int main() {
	scanf("%d", &N);
	int left=0, right=0;
	for (int i=0; i<N; i++) {
		scanf("%d", &money[i]);
		right = max(right, money[i]);
	}
	scanf("%d", &M);
	int ret = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			ret = max(ret, mid);
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}
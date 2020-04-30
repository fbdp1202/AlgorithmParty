// baekjoon 2343 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;

int N, M, lesson[MAX_N];

bool check(int here) {
	int count = 1;
	int cur = 0;
	for (int i=0; i<N; i++) {
		cur += lesson[i];
		if (cur > here) {
			cur = lesson[i];
			count++;
		}
	}
	return count <= M;
}

int main() {
	scanf("%d%d", &N, &M);
	int left = 0, right	= 1e9;
	for (int i=0; i<N; i++) {
		scanf("%d", &lesson[i]);
		left = max(left, lesson[i]);
	}

	int ret = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
			ret = min(ret, mid);
		} else {
			left = mid + 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}
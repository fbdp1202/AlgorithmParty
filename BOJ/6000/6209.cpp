// baekjoon 6209 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=50003;

int D, N, M, arr[MAX_N];

bool check(int dist) {
	int jump = 0;
	int pos = 0;
	while (pos < N+1) {
		int idx = lower_bound(arr, arr+N+3, arr[pos] + dist) - arr; // 최소 뛰어야 하는 거리
		if (idx == N+2) break;
		jump++;
		pos = idx;
	}
	return (N-M) <= (jump-1);
}

int main() {
	scanf("%d%d%d", &D, &N, &M);
	arr[0]=0; arr[N+1]=D;
	for (int i=1; i<=N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+N+2);
	arr[N+2]=2e9;

	int left=1, right=1e9;
	int ret=0;
	while (left <= right) {
		int mid = (left + right)/2;
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
// baekjoon 17951 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=100002;
const int MAX_INF=1e9;

int N, K;
int score[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) scanf("%d", &score[i]);

	int left = 0, right = 1;
	for (int i=0; i<N; i++) {
		right += score[i];
	}

	while (left + 1 < right) {
		int mid = (left+right)/2, cnt = 0, sum = 0;
		for (int i=0; i<N; i++) {
			sum += score[i];
			if (sum >= mid) {
				sum = 0;
				cnt++;
			}
		}
		if (cnt >= K) left = mid;
		else right = mid;
	}
	printf("%d\n", left);
	return 0;
}
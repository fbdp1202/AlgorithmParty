// baekjoon 15732 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,P>;

const int MAX_N=100001;
const int MAX_K=10001;

int N, K;
ll D;
PP boxes[MAX_K];

bool check(int here) {
	ll sum = 0;
	for (int i=0; i<K; i++) {
		int A, B, C;
		A = boxes[i].first;
		B = boxes[i].second.first;
		C = boxes[i].second.second;
		if (here < A) continue;
		sum += (min(here, B) - A)/C + 1;
	}
	return sum >= D;
}

int main() {
	scanf("%d%d%lld", &N, &K, &D);
	for (int i=0; i<K; i++) {
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		boxes[i] = PP(A, P(B, C));
	}

	int left = 1, right=1e6;
	int ret = 1e6;
	while (left <= right) {
		int mid = (left+right)/2;
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
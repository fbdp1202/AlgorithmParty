// baekjoon 2104 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N=100001;

int N;
ll ret, A[MAX_N];

ll solve(int a, int b) {
	if (a > b) return 0;
	if (b - a == 0) return A[a]*A[a];
	int mid = (a+b)/2;
	ll ret = max(solve(a, mid-1), solve(mid+1, b));
	ll sum = A[mid];
	ll minV = A[mid];
	ll left = mid, right = mid;
	while (1) {
		if (left == a && right == b) break;
		if (left == a) {
			right++;
			sum += A[right];
			minV = min(minV, A[right]);
			ret = max(ret, sum*minV);
		} else if (right == b) {
			left--;
			sum += A[left];
			minV = min(minV, A[left]);
			ret = max(ret, sum*minV);
		} else {
			if (A[left-1] >= A[right+1]) {
				left--;
				sum += A[left];
				minV = min(minV, A[left]);
				ret = max(ret, sum*minV);
			} else {
				right++;
				sum += A[right];
				minV = min(minV, A[right]);
				ret = max(ret, sum*minV);
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);
	printf("%lld\n", solve(0, N-1));
	return 0;
}
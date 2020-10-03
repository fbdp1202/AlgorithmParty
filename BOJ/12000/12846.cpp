// baekjoon 12846 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=100001;

int N, arr[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	stack<int> st;

	ll ret = 0;
	for (int i=0; i<N; i++) {
		int left = i;
		while (!st.empty() && arr[st.top()] > arr[i]) {
			ll height = arr[st.top()];
			st.pop();
			ll width = i;
			if (!st.empty()) {
				width = (i - st.top() - 1);
			}
			ret = max(ret, width*height);
		}
		st.push(i);
	}
	while (!st.empty()) {
		ll height = arr[st.top()];
		st.pop();
		ll width = N;
		if (!st.empty()) {
			width = N - st.top()-1;
		}
		ret = max(ret, width*height);
	}
	printf("%lld\n", ret);
	return 0;
}
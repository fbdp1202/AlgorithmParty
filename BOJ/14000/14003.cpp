// baekjoon 14003 yechan
#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

const int MAX_N=1000001;
const int MAX_INF=2e9;

int N, ans[MAX_N];
vector<P> tracking;
stack<int> st;

int main() {
	scanf("%d", &N);
	fill(ans, ans+N+1, MAX_INF);

	for (int i=0; i<N; i++) {
		int x;
		scanf("%d", &x);
		int idx = lower_bound(ans, ans+N+1, x) - ans;
		tracking.push_back(P(x, idx));
		ans[idx] = x;
	}

	int cnt = 0;
	while (ans[cnt] != MAX_INF) {
		cnt++;
	}
	printf("%d\n", cnt);

	cnt--;

	for (int i=tracking.size()-1; i>=0; i--) {
		if (cnt == tracking[i].second) {
			st.push(tracking[i].first);
			cnt--;
		}
	}

	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}
	puts("");
	return 0;
}
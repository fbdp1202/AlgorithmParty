// baekjoon 3015 yechan
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int N, x;
long long ret;

int main() {
	stack<pair<int,int> > st;
	scanf("%d", &N);
	int cnt=0;
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		while (!st.empty() && st.top().first < x) {
			ret+=st.top().second;
			st.pop();
		}
		cnt=0;
		while (!st.empty() && st.top().first == x) {
			cnt += st.top().second;
			st.pop();
		}
		ret += cnt;
		if (!st.empty()) ret++;
		st.push(make_pair(x, cnt+1));
	}
	printf("%lld\n", ret);
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX_N=100001;

typedef long long ll;
typedef pair<ll,ll> P;

int T, N;
ll l, r, x, y, ret;
P point[MAX_N];

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Case #%d\n", t);
		ret = 0;
		scanf("%lld%lld", &l, &r); // bound [l, r]
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%lld%lld", &x, &y);
			point[i].first = x;
			point[i].second = abs(y);
		}
		sort(point, point+N);
		ret = max(ret, (point[0].first - l)*2);
		ret = max(ret, (r - point[N-1].first)*2);
		stack<int> st;
		st.push(0);
		int pos = 1;
		while (pos < N) {
			int idx = st.top();
			if (point[idx].first == point[pos].first) pos++;
			else if (point[idx].second <= point[pos].second) {
				ret = max(ret, min(point[pos].first - point[idx].first, min((point[pos].first - l)*2,(r - point[idx].first)*2)));
				st.push(pos);
				pos++;
			} else {
				while (!st.empty() && point[st.top()].second > point[pos].second) {
					idx = st.top();
					st.pop();
					ll diff, height;
					if (st.empty()) {
						height = point[idx].second*2;
						ret = max(ret, min(height, (point[pos].first - l)*2));
					} else {
						diff = (point[pos].first - point[st.top()].first);
						height = min(point[idx].second*2, diff); // 만들수 있는 최대 정사각형
						ret = max(ret, min(height, min((point[pos].first - l)*2, (r - point[st.top()].first)*2)));
					}
				}
				st.push(pos);
			}
		}
		while (!st.empty()) {
			int idx = st.top();
			st.pop();
			if (st.empty()) ret = max(ret, point[idx].second*2);
			else {
				ret = max(ret, min(point[idx].second*2, (r - point[st.top()].first)*2));
			}
		}

		printf("%lld\n", ret);
	}
	return 0;
}
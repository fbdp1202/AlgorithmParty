// Postech algo Ploblem Assignment #4-3 Riverside Park
#include <cstdio>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, ll> P; 
int T, N;
ll W, l, r, y, tmpy;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &N, &W);
		ll ret = 0;
		stack<P> st;
		st.push(P({0LL, 0LL}, 0LL)); // (left, y)
		ll minY = 1e9;
		while (N--) {
			scanf("%lld%lld%lld", &l, &r, &y);
			minY = min(minY, y);
			while (st.top().second > y) {
				tmpy = st.top().second;
				st.pop();
				ret = max(ret, 1LL*(l-st.top().first.second)*tmpy);
			}
			st.push(P({l,r},y));
		}
		while (st.top().second) {
			tmpy = st.top().second;
			st.pop();
			ret = max(ret, 1LL*(W-st.top().first.second)*tmpy);
		}
		ret = max(ret, 1LL*minY*W);
		printf("%lld\n", ret);
	}
	return 0;
}
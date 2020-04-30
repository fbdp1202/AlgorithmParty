// baekjoon 16434 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,P>;

const int MAX_N=123457;

int N, ATK;
PP dungeon[MAX_N];

bool check(ll maxHP) {
	ll curHP = maxHP;
	ll curATK = ATK;

	for (int i=0; i<N; i++) {
		if (dungeon[i].first == 2) {
			curATK += dungeon[i].second.first;
			curHP = min(maxHP, curHP + dungeon[i].second.second);
		} else {
			ll monATK = dungeon[i].second.first;
			ll monHP = dungeon[i].second.second;
			ll count = (monHP+curATK-1)/curATK - 1;
			curHP -= count*monATK;
		}
		if (curHP <= 0) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &ATK);
	for (int i=0; i<N; i++) {
		int t, a, h;
		scanf("%d%d%d", &t, &a, &h);
		dungeon[i] = PP(t, P(a, h));
	}

	ll left=1, right=(1LL<<62);
	ll ret=(1LL<<62);
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
			ret = min(ret, mid);
		} else {
			left = mid + 1;
		}
	}
	printf("%lld\n", ret);
	return 0;
}
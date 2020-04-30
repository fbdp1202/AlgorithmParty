// baekjoon 3933 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
int N;
set<int> s;

ll backtracking(int pos, int K, int cnt) {
	if (K < 0) return 0;
	if (!K) return 1;
	if (pos*pos > K) return 0;
	if (cnt == 3) {
		if (s.count(K)) return 1;
		else return 0;
	}
	ll ret = 0;
	ret += backtracking(pos, K-pos*pos, cnt+1);
	ret += backtracking(pos+1, K, cnt);
	return ret;
}

int main() {
	for (int i=1; i*i<(1<<15); i++) {
		s.insert(i*i);
	}
	while (1) {
		scanf("%d", &N);
		if (!N) break;
		printf("%lld\n", backtracking(1, N, 0));
	}
	return 0;
}
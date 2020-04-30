// baekjoon 2659 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int tmp[4], data[5], ans, pos=1;

int dfs(int here, int start, int bound) {
	if (here == 4) {
		printf("%d: %d\n", pos++, ans);
		return 1;
	}
	int ret=0;

	for (int i=start; i<bound; i++) {
		ans*=10;
		ans+=i;
		ret += dfs(here+1, i, 10);
		ans/=10;
	}
	if (bound < 10) {
		ans*=10;
		ans+=bound;
		ret += dfs(here+1, bound, data[here+1]);
		ans/=10;
	}
	return ret;
}

int main() {
	for (int i=0; i<4; i++)
		scanf("%d", &tmp[i]);
	ans=0;
	for (int i=0; i<4; i++) {
		int t=0;
		for (int j=0; j<4; j++) {
			t *= 10;
			t += tmp[(i+j)%4];
		}
		ans = max(ans, t);
	}
	for (int i=3; i>=0; i--) {
		data[i] = ans%10;
		ans/=10;
	}

	ans=0;
	printf("%d\n", dfs(0, 1, data[0]));
	return 0;
}
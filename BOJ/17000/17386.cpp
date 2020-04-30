// baekjoon 17386 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,P> PP;

int ccw(const P &a, const P &b, const P &c) {
	long long op = 1LL*a.first*b.second + 1LL*b.first*c.second + 1LL*c.first*a.second;
	op -= 1LL*a.second*b.first + 1LL*b.second*c.first + 1LL*c.second*a.first;
	if (op > 0) return 1;
	if (op == 0) return 0;
	if (op < 0) return -1;
}

bool isOverlab(PP l1, PP l2) {
	P a = l1.first;
	P b = l1.second;
	P c = l2.first;
	P d = l2.second;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	PP a, b;
	scanf("%d%d%d%d", &a.first.first, &a.first.second, &a.second.first, &a.second.second);
	scanf("%d%d%d%d", &b.first.first, &b.first.second, &b.second.first, &b.second.second);
	printf("%d\n", isOverlab(a, b));
	return 0;
}
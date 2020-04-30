#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX_L=(1LL<<31);
const int MAX_N = 10001;

struct Point{
	ll l, r, y;
	Point(){}
	Point(ll l, ll r, ll y): l(l), r(r), y(y){}
};

bool cmp_y(const Point& a, const Point& b) {
	if (a.y == b.y) {
		if (a.l == b.l) {
			return a.r > b.r;
		}
		return a.l < b.l;
	}
	return a.y > b.y;
}

int T, N;
ll l, r, y;
Point pos[MAX_N];

void tophull(int index, ll left, ll right) {
	if (left == right) return;
	while (index < N) {
		if (pos[index].r < left || right < pos[index].l) index++;
		else break;
	}
	ll boundL=pos[index].l;
	ll boundR=pos[index].r;
	ll boundY=pos[index].y;
	while (index + 1 < N) {
		if (pos[index+1].y == boundY && pos[index+1].l <= boundR) {
			boundR = max(boundR, pos[index+1].r);
			index++;
		} else {
			break;
		}
	}
	if (N == index) return;
	boundR=min(boundR, right);
	boundL=max(boundL, left);
	tophull(index+1, left, boundL);
	if (boundL != boundR) printf("%lld %lld %lld\n", boundL, boundR, boundY);
	tophull(index+1, boundR, right);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i=0; i<N; i++) scanf("%lld%lld%lld", &pos[i].l, &pos[i].r, &pos[i].y);
		sort(pos, pos+N, cmp_y);
		tophull(0, 0, MAX_L);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX_N=100001;
const ll INF=1e10LL

struct Point{
	ll x, y;
	Point(){}
	Point(ll x, ll y):x(x), y(y){}
};

bool cmp_x(const Point& a, const Point& b) {
	return a.x < b.x;
}

bool cmp_y(const Point& a, const Point& b) {
	return a.y < b.y;
}

int T, N, X, Y;
Point pointX[MAX_N], pointY[MAX_N];

inline int getDistance(const Point& a, const Point& b) {
	return abs(a.x-b.x)+abs(a.y-b.y);
}

int bruthForce(int from, int to) {
	int ret = INF;
	for (int i=from; i<to; i++)
		for (int j=i+1; j<=to; j++)
			ret = min(ret, getDistance(pointX[i], pointX[j]));
	return ret;
}

ll findDistance(int from, int to) {
	if (to - from < 4) return bruthForce(from, to);
	ll ret = INF;
	int mid = (from + to)/2;
	int diff = min(findDistance(from, mid-1), findDistance(mid+1, to));
	vector<Point> v;
	for (int i=from, i<=to; i++) {
		if (pointX[i].x >= diff)
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%lld%lld", &X, &Y);
			pointX[i].x=pointY[i].x=X;
			pointX[i].y=pointY[i].y=Y;
		}
		sort(pointX, pointX+N, cmp_x);
		sort(pointy, pointy+N, cmp_y);
		printf("%lld\n", findDistance(0, N-1));
	}
	return 0;
}
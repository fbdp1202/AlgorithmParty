// baekjoon 11563 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
#define px first
#define py second
#define SQ(x) ((x)*(x))
typedef pair<double,double> P;
typedef pair<P, P> PP;
const double MAX_INF = 1000000.f;

int N, M;
double xs, ys, xe, ye;
PP A[2000], B[2000];

double cross(double x1, double y1, double x2, double y2) {
	return x1*y2-x2*y1;
}

double getCCW(P a, P b, P c) {
	return cross(b.px-a.px, b.py-a.py, c.px-a.px, c.py-a.py);
}

double getDistance(P a, P b) {
	return sqrt(SQ(a.px-b.px)+SQ(a.py-b.py));
}

P sub(P a, P b) {
	P c;
	c.px = a.px - b.px;
	c.py = a.py - b.py;
	return c;
}

double innerProduct(P a, P b) {
	return a.px*b.px + a.py*b.py;
}

bool isOverlab(int aidx, int bidx) {
	P a = A[aidx].px;
	P b = A[aidx].py;
	P c = B[bidx].px;
	P d = B[bidx].py;
	double ab = getCCW(a,b,c)*getCCW(a,b,d);
	double cd = getCCW(c,d,a)*getCCW(c,d,b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

double tracking(int aidx, int bidx) {
	if (isOverlab(aidx, bidx)) return 0.f;
	double ret = MAX_INF;
	P a = A[aidx].px;
	P b = A[aidx].py;
	P c = B[bidx].px;
	P d = B[bidx].py;
	ret = min(ret, getDistance(a, c));
	ret = min(ret, getDistance(a, d));
	ret = min(ret, getDistance(b, c));
	ret = min(ret, getDistance(b, d));

	double dot1 = innerProduct(sub(b,a), sub(c,a));
	double dot2 = innerProduct(sub(a,b), sub(c,b));

	double dot3 = innerProduct(sub(b,a), sub(d,a));
	double dot4 = innerProduct(sub(a,b), sub(d,b));

	if (dot1*dot2 >= 0) {
		ret = min(ret, abs(getCCW(a,b,c))/getDistance(a,b));
	}

	if (dot3*dot4 >= 0) {
		ret = min(ret, abs(getCCW(a,b,d))/getDistance(a,b));
	}
	return ret;
}

int main() {
	double ret = MAX_INF;
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%lf %lf %lf %lf", &xs, &ys, &xe, &ye);
		A[i] = {{xs, ys}, {xe, ye}};
	}
	
	for (int i=0; i<M; i++) {
		scanf("%lf %lf %lf %lf", &xs, &ys, &xe, &ye);
		B[i] = {{xs, ys}, {xe, ye}};
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			ret = min(ret, tracking(i, j));
		}
	}
	printf("%.16lf", ret);

	return 0;
}
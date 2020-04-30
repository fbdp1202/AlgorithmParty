#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
#define SQ(x) ((x)*(x))
#define PI acos(0)*2
typedef pair<double, double> Pdd;

int T, R, S, E, N;
int l, r, h;
double ret = 0;

double getCos(double R, double h) {
	return (R-h)/R;
}

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Case #%d\n", t);
		ret = 0;
		scanf("%d%d%d", &R, &S, &E);
		scanf("%d", &N);
		double prev_x = S;
		for (int i=0; i<N; i++) {
			scanf("%d%d%d", &l, &r, &h);
			ret += r - l;
			if (R > h) {
				double d = sqrt(double(R*R - (R-h)*(R-h)));
				ret += l - d - prev_x;
				ret += 2*R*acos(getCos(R, h));
				prev_x = r + d;
			} else {
				ret += l - prev_x - R;
				ret += (h-R)*2;
				ret += PI*R;
				prev_x = r + R;
			}
		}
		ret += E - prev_x;
		printf("%.12lf\n", ret);
	}
	return 0;
}
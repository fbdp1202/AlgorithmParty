#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX_N=100001;
typedef long long ll;

int N, K;
pair<double,double> position[MAX_N];

bool ispossible(double diff)
{
	double bottom, top;

	int count = 1;
	bottom = top = position[0].second;
	for (int i=1; i<N; i++) {
		bottom = min(position[i].second, bottom);
		top = max(position[i].second, top);
		if (top - bottom > diff) {
			count++;
			bottom = top = position[i].second;
		}
		if (count > K) return false;
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		for (int i=0; i<N; i++)
			scanf("%lf%lf", &position[i].first, &position[i].second);

		sort(position, position+N);

		double ret = 2e8;

		double left=0, right=2e8;
		while ((right - left) > 0.001) {
			double mid = (left + right) / 2;
			if (ispossible(mid)) {
				ret = min(ret, mid);
				right = mid;
			} else {
				left = mid;
			}
		}

		printf("%.1lf\n", ret/2.f);
	}
	return 0;
}
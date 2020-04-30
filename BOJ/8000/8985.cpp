// baekjoon 8985 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using PP = pair<int, P>;

const int MAX_N=500001;

int N, K, height[MAX_N], hole[MAX_N], water[MAX_N];
PP line[MAX_N];

int rangeHoles(int s, int e) {
	return hole[e]-hole[s-1];
}

double drainWater(int s, int e, int h, int idx) {
	// printf("drainWater(%d, %d, %d, %d)\n", s, e, h, idx);
	if (s > e) return 0;

	if (rangeHoles(s, e) == 0) {
		for (int i=s; i<=e; i++) water[i]=h;
		return 0;
	}
	if (s == e) {
		return (double)(height[s] - h);
	}

	while ((line[idx].second.first < s || line[idx].second.second > e) && (idx < N/2)) idx++;

	double t = 0;

	int next_h = line[idx].first;
	int next_s = s;
	int next_idx = idx;
	while ((next_h == line[next_idx].first) && next_idx < N/2) next_idx++;

	while ((next_h == line[idx].first) && (idx < N/2)) {
		if (line[idx].second.first < s || line[idx].second.second > e) {
			idx++;
			continue;
		}
		t = max(t, drainWater(next_s, line[idx].second.first-1, next_h, next_idx));
		next_s = line[idx].second.second + 1;
		idx++;
	}
	t = max(t, drainWater(next_s, e, next_h, next_idx));
	double cur_t = 1.0*(1LL*(e-s+1)*(next_h-h))/rangeHoles(s,e);
	return t+cur_t;
}

int main() {
	scanf("%d", &N);
	P pv;
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (i%2 == 0) {
			if (pv.first+1 <= x) line[i/2] = PP(y, P(pv.first+1, x));
			for (int i=pv.first+1; i<=x; i++) {
				height[i]=y;
				water[i]=height[i];
			}
		}
		pv = P(x, y);
	}
	sort(line, line+N/2);

	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		hole[c]++;
	}

	for (int i=1; i<MAX_N; i++)
		hole[i] += hole[i-1];

	double t=0;
	int s=1, e=0;
	for (int i=1; i<MAX_N; i++) {
		if (height[i] == 0) {
			if (e) {
				t = max(t, drainWater(s, e, 0, 1));
			}
			s=i+1;
			e=0;
		} else {
			e=i;
		}
	}
	printf("%.2lf\n", t);

	ll ret = 0;
	for (int i=1; i<MAX_N; i++) {
		ret += (height[i] - water[i]);
	}
	printf("%lld\n", ret);

	return 0;
}
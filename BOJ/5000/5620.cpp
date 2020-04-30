// baekjoon 5620 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
#define SQ(x) ((x)*(x))

const int MAX_N=5e5;

int N;
P point[MAX_N];

inline int getDist(const P a, const P b) {
	return SQ(a.first - b.first)+SQ(a.second - b.second);
}

int minDist(int left, int right) {
	if (right - left == 2) {
		int ret = 1e9;
		ret = min(ret, getDist(point[left], point[left+1]));
		ret = min(ret, getDist(point[left], point[left+2]));
		ret = min(ret, getDist(point[left+1], point[left+2]));
		return ret;
	}
	if (right - left == 1) {
		return getDist(point[left], point[right]);
	}

	int ret = 1e9;
	int mid = (left + right)/2;
	ret = min(minDist(left,mid), minDist(mid,right));

	vector<P> ysort;
	for (int i=left; i<=right; i++) {
		if (ret > SQ(point[mid].first - point[i].first))
			ysort.push_back(P(point[i].second, point[i].first));
	}
	sort(ysort.begin(), ysort.end());

	int limit = ysort.size();
	for (int i=0; i<limit; i++) {
		for (int j=i+1; j<limit; j++) {
			if (ret < SQ(ysort[i].first - ysort[j].first)) break;
			ret = min(ret, getDist(ysort[i], ysort[j]));
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &point[i].first, &point[i].second);

	sort(point, point+N);
	printf("%d\n", minDist(0,N-1));
	return 0;
}
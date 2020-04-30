// baekjoon 13303 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_INF=1e9;

int N, sy, ex;
vector<tuple<int,int,int>> lines;

int main() {
	scanf("%d%d%d", &N, &sy, &ex);
	for (int i=0; i<N; i++) {
		int x, yl, yh;
		scanf("%d%d%d", &x, &yl, &yh);
		lines.push_back(make_tuple(x, yl, yh));
	}
	sort(lines.begin(), lines.end());
	set<pair<int,int>> s;
	s.insert(make_pair(sy,0));
	for (int i=0; i<N; i++) {
		int x, yl, yh;
		tie(x, yl, yh) = lines[i];
		auto lb = s.lower_bound(make_pair(yl, -MAX_INF));
		auto ub = s.upper_bound(make_pair(yh,  MAX_INF));
		int top = MAX_INF, bottom = MAX_INF;
		for (auto it=lb; it!=ub; it++) {
			top = min(top, it->second + (yh - it->first));
			bottom = min(bottom, it->second + (it->first - yl));
		}
		s.erase(lb, ub);
		s.insert(make_pair(yh, top));
		s.insert(make_pair(yl, bottom));
	}

	int minV = MAX_INF;
	int minCnt = 0;
	for (auto it=s.begin(); it!=s.end(); it++) {
		if (minV == it->second) {
			minCnt++;
		} else if (it->second < minV) {
			minV = it->second;
			minCnt=1;
		}
	}
	printf("%d\n%d ", minV+ex, minCnt);
	for (auto it=s.begin(); it!=s.end(); it++)
		if (minV == it->second)
			printf("%d ", it->first);
	puts("");
	return 0;
}
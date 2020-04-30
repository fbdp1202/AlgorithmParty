// baekjoon 10165 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=500001;

struct Point{
	int x, y, idx;
	Point():Point(0,0,0){}
	Point(int x1, int y1, int idx1):x(x1),y(y1),idx(idx1){}
	bool operator<(const Point &o) {
		if (x == o.x) return y > o.y;
		return x < o.x;
	}
};

int N, M;
vector<Point> ga, gb;
bool visited[MAX_N];

void cancel(vector<Point> &v) {
	int bound = -1;
	sort(v.begin(), v.end());
	for (Point &p: v) {
		int b = p.y;
		int idx = p.idx;
		if (b <= bound) visited[idx]=true;
		bound = max(bound, b);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	int x=N, y=-1;
	for (int i=0; i<M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b) {
			ga.push_back(Point(a, b, i));
		} else {
			x = min(x, a);
			y = max(y, b);
			gb.push_back(Point(a, b, i));
		}
	}

	for (Point &p: ga) {
		int a = p.x;
		int b = p.y;
		int idx = p.idx;
		if (x <= a || b <= y) visited[idx]=true;
	}

	cancel(ga);
	cancel(gb);

	for (int i=0; i<M; i++)
		if (!visited[i])
			printf("%d ", i+1);
	puts("");
	return 0;
}
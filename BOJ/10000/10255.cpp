// baekjoon 10255_2 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Point{
	int x, y;
	Point():x(0), y(0){}
	Point(int x, int y):x(x), y(y){}
	bool operator>(const Point &o) {
		return (o.x == x) ? y > o.y : x > o.x;
	}
	bool operator<(const Point &o) {
		return (o.x == x) ? y < o.y : x < o.x;
	}
	bool operator<=(const Point &o) {
		return (o.x == x) ? y <= o.y : x <= o.x;
	}
	bool operator==(const Point &o) {
		return (x == o.x) && (y == o.y);
	}
};

struct Line{
	Point pos[2];
	Line(){};
	Line(Point a, Point b){ pos[0]=a; pos[1]=b; }
};

int getCCW(Point a, Point b, Point c) {
	int res = (a.x*b.y + b.x*c.y + c.x*a.y);
	res -= (a.x*c.y + b.x*a.y + c.x*b.y);
	return (res) ? ((res < 0) ? -1 : 1) : 0;
}

int isISTPoint(Line rline, Line line) {
	Point a = line.pos[0];
	Point b = line.pos[1];
	Point c = rline.pos[0];
	Point d = rline.pos[1];

	int ccw[4];
	ccw[0] = getCCW(a, b, c), ccw[1] = getCCW(a, b, d);
	ccw[2] = getCCW(c, d, a), ccw[3] = getCCW(c, d, b);

	int ab = ccw[0]*ccw[1];
	int cd = ccw[2]*ccw[3];
	if (ccw[0] == 0 && ccw[0] == ccw[1]) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (ccw[2] == 0 && ccw[2] == ccw[3]) { // 평행할때
			if (b < c || d < a) return 0; // 평행 하지만 겹치지 않음
			if (b == c || d == a) return 1; // 1점만 겹침
			return -1; // 해가 많음 (4)
		}
		return 1;
	}
	return (ab <= 0 && cd <= 0);
}

int Solve(vector<Line> rect, Line line) {
	int ans = 0;
	for (int i=0; i<4; i++){
		int tmp = isISTPoint(rect[i], line);
		if (tmp == -1) return 4;
		ans += tmp;
		if (isISTPoint(Line(rect[i].pos[0], rect[i].pos[0]), line)) ans--; // 각 모서리 중복 제거
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i=0; i<T; i++) {
		vector<Line> rect;
		Line line;
		int xmin, ymin, xmax, ymax;
		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
		rect.push_back(Line(Point(xmin, ymin), Point(xmax,ymin)));
		rect.push_back(Line(Point(xmax, ymin), Point(xmax,ymax)));
		rect.push_back(Line(Point(xmax, ymax), Point(xmin,ymax)));
		rect.push_back(Line(Point(xmin, ymax), Point(xmin,ymin)));
		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
		line = Line(Point(xmin, ymin), Point(xmax, ymax));
		int ret = Solve(rect, line);
		printf("%d\n", ret);
	}
	return 0;
}
// baekjoon 10158 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int W, H, p, q, t, dx, dy, dist;

inline int goToBound(int x, int y) {
	return min(dx>0 ? W-x : x, dy>0 ? H-y : y);
}

inline int turnDirect() {
	if (!(p-W) || !p) dx*=-1;
	if (!(q-H) || !q) dy*=-1;
}

int main() {
	scanf("%d%d", &W, &H);
	scanf("%d%d", &p, &q);
	scanf("%d", &t);
	dx = dy = 1;
	while (t) {
		dist = min(t, goToBound(p, q));
		t -= dist;
		p += dx*dist;
		q += dy*dist;
		turnDirect();
	}
	printf("%d %d\n", p, q);
	return 0;
}
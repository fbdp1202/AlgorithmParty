// baekjoon 1004 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define sqrt(x) (x)*(x)

int T, N, sx, sy, ex, ey, cx, cy, cr;

bool CheckPointInCyle(int x, int y, int center_x, int center_y, int cycle_r) {
	return sqrt(cycle_r) >= sqrt(center_x-x)+sqrt(center_y-y);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		int result=0;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%d %d %d", &cx, &cy, &cr);
			if (CheckPointInCyle(sx, sy, cx, cy, cr) ^ CheckPointInCyle(ex, ey, cx, cy, cr))
				result++;
		}
		printf("%d\n", result);
	}
	return 0;
}
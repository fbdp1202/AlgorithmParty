// baekjoon 11650 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
	bool operator<(const Point &O) {
		if (x == O.x) return y < O.y;
		return x < O.x;
	}
};

int N;
Point pos[100000];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &pos[i].x, &pos[i].y);

	sort(pos, pos+N);

	for (int i=0; i<N; i++)
		printf("%d %d\n", pos[i].x, pos[i].y);

	return 0;
}
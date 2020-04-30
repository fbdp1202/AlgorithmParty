// baekjoon 2527 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int x1, x2, y1, y2, p1, p2, q1, q2;

bool checkOutSize() {
	if (p2 < x1) return true;
	if (p1 < x2) return true;
	if (q2 < y1) return true;
	if (q1 < y2) return true;
	return false;
}

bool checkLine() {
	if (x1 == p2) return true;
	if (q1 == y2) return true;
	if (p1 == x2) return true;
	if (y1 == q2) return true;
	return false;
}

bool checkDot() {
	if (x1 == p2 && q1 == y2) return true; // left top
	if (x1 == p2 && y1 == q2) return true; // left bottom
	if (p1 == x2 && q1 == y2) return true; // right top
	if (p1 == x2 && y1 == q2) return true; // right bottom
	return false;
}

int main() {
	for (int i=0; i<4; i++) {
		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &p1, &q1, &x2, &y2, &p2, &q2);
		if (checkOutSize()) puts("d");
		else if (checkDot()) puts("c");
		else if (checkLine()) puts("b");
		else puts("a");
	}
	return 0;
}
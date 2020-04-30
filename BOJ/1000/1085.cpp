// baekjoon 1085
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int x, y, w, h, dx, dy;
	cin >> x >> y >> w >> h;
	dx = w-x; dy = h-y;
	cout << min(min(dx, x), min(dy, y));
}
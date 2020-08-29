#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int main() {
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	int x = (c*e-b*f)/(a*e-b*d);
	int y = (-c*d+a*f)/(a*e-b*d);
	printf("%d %d\n", x, y);
	return 0;
}
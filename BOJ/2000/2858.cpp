// baekjoon 2858 yechan
#include <bits/stdc++.h>
using namespace std;

double R, B;

void go(double a, double b, double c) {
	double d = -b/2;
	double e = sqrt(b*b-4*a*c)/2;
	printf("%.0lf %.0lf\n", d+e, d-e);
}

int main() {
	scanf("%lf%lf", &R, &B);
	go(1, -(R/2+2), R+B);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

double N, B, M;

int main() {
	while (scanf("%lf%lf%lf", &N, &B, &M) != -1) {
		int year = 0;
		while (N > M) {
			N += N*B/100.f;
			year++;
		}
		printf("%d\n", year);
	}
	return 0;
}
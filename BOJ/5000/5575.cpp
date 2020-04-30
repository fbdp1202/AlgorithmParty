// baekjoon 5575 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, C, h, m, s;
int main() {
	scanf("%d %d %d", &h, &m, &s);
	A -= h*3600 + m*60 + s;
	scanf("%d %d %d", &h, &m, &s);
	A += h*3600 + m*60 + s;

	scanf("%d %d %d", &h, &m, &s);
	B -= h*3600 + m*60 + s;
	scanf("%d %d %d", &h, &m, &s);
	B += h*3600 + m*60 + s;

	scanf("%d %d %d", &h, &m, &s);
	C -= h*3600 + m*60 + s;
	scanf("%d %d %d", &h, &m, &s);
	C += h*3600 + m*60 + s;

	printf("%d %d %d\n", A/3600, (A%3600)/60, A%60);
	printf("%d %d %d\n", B/3600, (B%3600)/60, B%60);
	printf("%d %d %d\n", C/3600, (C%3600)/60, C%60);
	return 0;
}
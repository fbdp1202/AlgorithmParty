// baekjoon 17388 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	int minV = min(A, min(B, C));
	if (A + B + C >= 100) puts("OK");
	else if (minV == A) puts("Soongsil");
	else if (minV == B) puts("Korea");
	else if (minV == C) puts("Hanyang");
	return 0;
}
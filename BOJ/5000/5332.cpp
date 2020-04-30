// baekjoon 5332 yechan
#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
	int L, A, B, C, D;
	scanf("%d%d%d%d%d", &L,&A,&B,&C,&D);
	printf("%d", L-max((A+C-1)/C, (B+D-1)/D));
	return 0;
}
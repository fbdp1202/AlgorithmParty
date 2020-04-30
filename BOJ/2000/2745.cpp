// baekjoon 2745 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char S[40];
int N, B, d;

int main() {
	scanf("%s %d", S, &B);
	for (int i=0; S[i]; i++) {
		N*=B;
		if ('A' <= S[i]) d=S[i]-'A'+10;
		else d=S[i]-'0';
		N+=d;
	}
	printf("%d\n", N);
	return 0;
}
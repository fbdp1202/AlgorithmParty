// baekjoon 13277 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char A[300001], B[300001];
int C[600001], memo[10][10];

void f(char *a, int la, char *b, int lb, int *c) {
	for (int i=0; i<lb; i++) {
		for (int j=0; j<la; j++) {
			c[i+j] += memo[a[la-j-1]-'0'][b[lb-i-1]-'0'];
		}
	}

	int maxidx = 0;
	for (int i=0; i<la+lb; i++) {
		c[i+1] += c[i]/10;
		c[i] %= 10;
		if (c[i+1]) maxidx = i+1;
	}

	for (int i=maxidx; i>=0; i--) {
		printf("%d", c[i]);
	}
	puts("");
}

int main() {
	scanf("%s %s", A, B);
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			memo[i][j] = i*j;
		}
	}

	int la = strlen(A), lb = strlen(B);
	f(A, la, B, lb, C);
	return 0;
}
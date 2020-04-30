// baekjoon 2935 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int la, lb, zeronum;
char A[101], B[101];
char op;

int main() {
	scanf("%s %c %s", A, &op, B);
	for (; A[la]; la++);
	for (; B[lb]; lb++);
	if (op == '*') {
		zeronum = la-1 + lb-1;
		printf("1");
		for (int i=0; i<zeronum; i++) {
			printf("0");
		}
		puts("");
	}
	else {
		if (la == lb) {
			printf("2");
			for (int i=0; i<la-1; i++) {
				printf("0");
			}
		} else {
			if (la < lb) swap(la, lb);
			printf("1");
			for (int i=la-1; i>=1; i--) {
				if (lb == i) printf("1");
				else printf("0");
			}
			puts("");
		}
	}
	return 0;
}
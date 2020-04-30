// baekjoon 2445
#include <cstdio>
using namespace std;

int N;
int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		for (int j=0; j<i; j++) printf("*");
		for (int j=0; j<N-i; j++) printf(" ");
		for (int j=0; j<N-i; j++) printf(" ");
		for (int j=0; j<i; j++) printf("*");
		puts("");
	}
	for (int i=N-1; i>=1; i--) {
		for (int j=0; j<i; j++) printf("*");
		for (int j=0; j<N-i; j++) printf(" ");
		for (int j=0; j<N-i; j++) printf(" ");
		for (int j=0; j<i; j++) printf("*");
		puts("");
	}
	return 0;
}
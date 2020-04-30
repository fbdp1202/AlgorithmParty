// baekjoon 14624 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	if (N % 2) {
		for (int i=0; i<N; i++)
			printf("*");
		puts("");

		for (int i=0; i<N/2; i++) printf(" ");
		printf("*\n");

		for (int i=1; i<=N/2; i++) {
			for (int j=i; j<N/2; j++) printf(" ");
			printf("*");
			for (int j=N/2-i+1; j<N/2; j++) printf(" ");
			printf(" ");
			for (int j=N/2-i+1; j<N/2; j++) printf(" ");
			printf("*\n");
		}
	} else {
		printf("I LOVE CBNU\n");
	}
	return 0;
}
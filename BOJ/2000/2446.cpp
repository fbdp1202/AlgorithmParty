// baekjoon 2446 yechan
#include <cstdio>
using namespace std;

int N;

int main() {
	scanf("%d", &N);

	for (int i=0; i<N-1; i++) {
		for (int j=0; j<i; j++) printf(" ");
		for (int j=2*N-2-2*i; j>=0; j--) printf("*");
		puts("");
	}

	for (int i=N-1; i>=0; i--) {
		for (int j=0; j<i; j++) printf(" ");
		for (int j=2*N-2-2*i; j>=0; j--) printf("*");
		puts("");
	}

	return 0;
}
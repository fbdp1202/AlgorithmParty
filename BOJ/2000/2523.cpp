// baekjoon 2522 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<=i; j++) printf("*");
		puts("");
	}
	for (int i=N-2; i>=0; i--) {
		for (int j=0; j<=i; j++) printf("*");
		puts("");
	}
	return 0;
}
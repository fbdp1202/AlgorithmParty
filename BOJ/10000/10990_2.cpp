// baekjoon 10990 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N-i-1; j++) printf(" ");
		printf("*");
		for (int j=0; j<2*i-1; j++) printf(" ");
		if (i) printf("*");
		puts("");
	}
	return 0;
}
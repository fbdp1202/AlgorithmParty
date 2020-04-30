// baekjoon 10992 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int main() {
	scanf("%d", &N);
	for (int i=0; i<N-1; i++) {
		for (int j=0; j<N-i-1; j++) printf(" ");
		printf("*");
		for (int j=0; j<i*2-1; j++) printf(" ");
		if (i) printf("*");
		puts("");
	}
	for (int i=0; i<N*2-1; i++) printf("*");
	puts("");

	return 0;
}
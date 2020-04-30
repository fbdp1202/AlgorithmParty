// baekjoon 10995 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		if (i & 1) printf(" ");
		for (int j=0; j<N; j++) printf("* ");
		puts("");
	}
	return 0;
}
// baekjoon 10991
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N-i-1; j++) printf(" ");
		for (int j=0; j<=i; j++) printf("* ");
		puts("");
	}
	return 0;
}
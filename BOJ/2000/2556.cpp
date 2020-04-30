// baekjoon 2556 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
			printf("*");
		puts("");
	}
}
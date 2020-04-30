// baekjoon 2442 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int N;

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		for (int j=N-i-1; j>=0; j--)
			printf(" ");
		for (int j=0; j<i*2-1; j++)
			printf("*");
		puts("");
	}
}

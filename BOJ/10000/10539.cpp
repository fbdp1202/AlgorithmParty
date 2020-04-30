// baekjoon 10539 yechan
#include <cstdio>
using namespace std;

int N, prev, curr, X;
int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &X);
		curr=X*i;
		printf("%d ",curr-prev);
		prev=curr;
	}
	return 0;
}
// baekjoon 2592 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, X, visit[101], result, maxV, maxC;
int main() {
	for (int i=0; i<10; i++) {
		scanf("%d", &X);
		result += X;
		visit[X/10]++;
		if (maxC < visit[X/10]) {
			maxC = visit[X/10];
			maxV = X;
		}
	}
	printf("%d\n%d\n", result/10, maxV);
	return 0;
}
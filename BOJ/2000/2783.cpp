// baekjoon 2783 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
float X, Y, result;

int main() {
	scanf("%d%d", &X, &Y);
	result = X/Y*1000;
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d", &X, &Y);
		result = min(result, X/Y*1000);
	}
	printf("%.2f\n", result);
}
// baekjoon 11772 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, X, result;

int mul(int X, int c, int d){
	if (c == d) return 1;
	return X*mul(X, c+1, d);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &X);
		result += mul(X/10, 0, X%10);
	}
	printf("%d\n", result);
	return 0;
}
// baekjoon 10409 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int n, T, X, cnt, curr;

int main() {
	scanf("%d%d", &n, &T);
	for (int i=0; i<n; i++){
		scanf("%d", &X);
		curr+=X;
		if (curr <= T) cnt++;
		else break;
	}
	printf("%d\n", cnt);
	return 0;
}
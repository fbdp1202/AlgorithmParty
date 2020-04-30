// baekjoon 10813 yechan
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[101];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		arr[i]=i;
	for (int i=0; i<M; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		swap(arr[x], arr[y]);
	}
	for (int i=1; i<=N; i++)
		printf("%d ", arr[i]);
	puts("");
	return 0;
}
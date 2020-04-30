// baekjoon 1182 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=21;

int N, S;
int arr[MAX_N];

int dfs(int here, int sum, int size) {
	if (here == N) return ((sum == S) && (size > 0));
	return dfs(here+1, sum+arr[here], size+1)+dfs(here+1, sum, size);
}

int main() {
	scanf("%d%d", &N, &S);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", dfs(0, 0, 0));
	return 0;
}
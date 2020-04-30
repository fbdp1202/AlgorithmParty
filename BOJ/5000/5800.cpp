// baekjoon 5800 yechan
#include <bits/stdc++.h>
using namespace std;

int T, x, K;
int arr[101];

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%d", &K);
		for (int i=0; i<K; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+K);
		int maxV = arr[K-1], minV = arr[0];
		int gap = 0;
		for (int i=0; i<K-1; i++)
			gap = max(gap, arr[i+1]-arr[i]);
		printf("Class %d\n", t);
		printf("Max %d, Min %d, Largest gap %d\n", maxV, minV, gap);
	}
	return 0;
}
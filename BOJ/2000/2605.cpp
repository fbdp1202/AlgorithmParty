// baekjoon 2605 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, line[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		line[i]=i+1;
	for (int i=0; i<N; i++) {
		int x;
		scanf("%d", &x);
		for (int j=0; j<x; j++)
			swap(line[i-j], line[i-j-1]);
	}

	for (int i=0; i<N; i++)
		printf("%d ", line[i]);
	puts("");
	return 0;
}
// baekjoon 16122 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10

int N, M;
int arr[MAX_N*2+2];

void backtracking(int curr, int count) {
	if (count == N) {
		arr[curr+MAX_N]++;
		return;
	}
	backtracking(-curr, count+1);
	backtracking(~curr, count+1);
}

int main() {
	scanf("%d%d", &N, &M);
	backtracking(0, 0);
	for (int i=0; i<MAX_N*2+2; i++)
		printf("%d ", i-MAX_N);
	puts("");
	for (int i=0; i<MAX_N*2+2; i++)
		printf("%d ", arr[i]);
	puts("");
	return 0;
}
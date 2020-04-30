// baekjoon 16435 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001
int N, L, fruit[MAX_N];

int main() {
	scanf("%d%d",&N, &L);
	for (int i=0; i<N; i++)
		scanf("%d", &fruit[i]);
	sort(fruit, fruit+N);

	for (int i=0; i<N; i++) {
		if (fruit[i] > L) break;
		L++;
	}
	printf("%d\n", L);
	return 0;
}
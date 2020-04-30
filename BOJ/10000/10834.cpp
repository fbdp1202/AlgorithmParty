// baekjoon 10834 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, s, a, b, cur=1;

int main() {
	scanf("%d", &N);
	int dir = 0;
	for (int i=0; i<N; i++) {
		scanf("%d%d%d", &a, &b, &s);
		dir = (dir+s)%2;
		cur = (cur / a) * b;
	}
	printf("%d %d\n", dir, cur);
	return 0;
}
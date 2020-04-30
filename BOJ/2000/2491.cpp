// baekjoon 2491 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int N, x, px=-1, up, down;

int main() {
	scanf("%d", &N);
	int ret=0;
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		if (px == x) up++, down++;
		else if (px < x) up++, down=1;
		else up=1,down++;
		px = x;
		ret = max(ret, max(up, down));
	}
	printf("%d\n", ret);
	return 0;
}
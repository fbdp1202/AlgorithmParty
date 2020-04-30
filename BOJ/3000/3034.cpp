// baekjoon 3034 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int N, W, H, x;
int main() {
	scanf("%d%d%d", &N, &W, &H);
	W = sqrt(W*W+H*H);
	while (N--) {
		scanf("%d", &x);
		if (x <= W) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}
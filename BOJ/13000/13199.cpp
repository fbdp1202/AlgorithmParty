// baekjoon 13199 yechan
#include <cstdio>
using namespace std;
int T, P, M, F, C;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &P, &M, &F, &C);
		int coupon = (M/P)*C;
		int rst = 0;
		coupon = (coupon/F)*C + coupon%F;
		while(coupon >= F) {
			rst += coupon/F;
			coupon = (coupon/F)*C + coupon%F;
		}
		printf("%d\n", rst);
	}
	return 0;
}
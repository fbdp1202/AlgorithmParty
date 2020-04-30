// baekjoon 10214 yechan
#include <cstdio>
using namespace std;

int T, x, y, yonsei, korea;

int main() {
	scanf("%d", &T);
	while (T--) {
		yonsei = korea = 0;
		for (int i=0; i<9; i++) {
			scanf("%d%d", &x, &y);
			yonsei += x;
			korea += y;
		}
		if (yonsei == korea) puts("Draw");
		else if (yonsei < korea) puts("Korea");
		else puts("Yonsei");
	}
	return 0;
}
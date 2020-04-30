// baekjoon 1011 yechan
#include <cstdio>
#include <cmath>
int T, x, y, d, sd;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &x, &y);
		d=y-x; 	sd=sqrt(d);
		if (sd*sd == d)
			printf("%d\n", sd*2-1);
		else if (d <= sd*sd + sd)
			printf("%d\n", sd*2);
		else
			printf("%d\n", sd*2+1);
	}
	return 0;
}
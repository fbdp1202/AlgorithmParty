#include <cstdio>
#include <algorithm>
using namespace std;
int q, a;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &a);
		int cnt = 0;
		int tmp = a;
		// int ret = 0;
		// for (int i=2; i<a; i++) {
		// 	int data1 = i ^ a;
		// 	int data2 = i & a;
		// 	ret = max(ret, gcd(data1, data2));
		// }
		// printf("%d\n", ret);
		while (a) {
			a >>= 1;
			cnt++;
		}
		if (tmp==(1<<cnt)-1) {
			if (cnt % 2 == 0) {
				int ret = 0;
				for (int i=0; i<cnt; i++) {
					if (i % 2 == 0) ret |= (1<<i);
				}
				printf("%d\n", ret);
			} else {
				printf("1\n");
			}
		}
		else printf("%d\n", (1<<cnt)-1);
	}
	return 0;
}
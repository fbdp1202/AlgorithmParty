// baekjoon 4435 yechan
#include <bits/stdc++.h>
using namespace std;

const int A[6] = {1, 2, 3, 3, 4, 10};
const int B[7] = {1, 2, 2, 2, 3, 5, 10};
int T;

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Battle %d: ", t);
		int x;
		int ret = 0;
		for (int i=0; i<6; i++) {
			scanf("%d", &x);
			ret += x*A[i];
		}
		for (int i=0; i<7; i++) {
			scanf("%d", &x);
			ret -= x*B[i];
		}
		if (ret > 0) printf("Good triumphs over Evil\n");
		else if (ret < 0) printf("Evil eradicates all trace of Good\n");
		else printf("No victor on this battle field\n");
	}
	return 0;
}
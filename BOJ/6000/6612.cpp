// baekjoon 6612 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_L 100000
int L, A, ants[MAX_L];
int main() {
	while (scanf("%d%d", &L, &A) != -1) {
		int pos=0;
		int posleft = -1, posright=-1;
		char ch;
		for (int i=0; i<A; i++) {
			scanf("%d %c", &ants[i], &ch);
			if (ch == 'L') {
				posleft = max(posleft, ants[i]);
				pos++;
			}
			else {
				posright = max(posright, L-ants[i]);
			}
		}
		sort(ants, ants+A);
		printf("The last ant will fall down in %d seconds - started at ",max(posleft,posright));
		if (posleft < posright) printf("%d", ants[pos]);
		else printf("%d", ants[pos-1]);
		if (posleft == posright) printf(" and %d", ants[pos]);
		puts(".");
	}
	return 0;
}
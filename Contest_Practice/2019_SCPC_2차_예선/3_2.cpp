#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int T, L, S, E, A, B;
int top[MAX_N], bottom[MAX_N];

int main() {
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		printf("Case #%d\n", test);
		scanf("%d%d%d", &L, &S, &E);
		scanf("%d", &A);
		for (int i=0; i<A; i++)
			scanf("%d", &top[i]);
		scanf("%d", &B);
		for (int i=0; i<B; i++)
			scanf("%d", &bottom[i]);

		if (A <= 100 && B <= 100) {

		} else {
			printf("0")
		}
	}
	return 0;
}
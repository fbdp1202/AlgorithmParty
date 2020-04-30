// baekjoon 1547 yechan
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int M, a, b, ball = 1;
	scanf("%d", &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d", &a, &b);
		if (a == ball || b == ball) {
			if (a == ball) 	ball = b;
			else 			ball = a;
		}
	}

	printf("%d\n", ball);
	return 0;
}
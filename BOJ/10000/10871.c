// baekjoon 10871
#include <stdio.h>

int main(void) {
	int N, X;
	int num;
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (X > num)
			printf("%d ", num);
	}
	return 0;
}
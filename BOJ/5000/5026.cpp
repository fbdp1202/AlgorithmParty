// baekjoon 5026 yechan
#include <bits/stdc++.h>
using namespace std;

char str[11];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		if (str[0] == 'P') {
			printf("skipped\n");
			continue;
		}
		int A, B;
		sscanf(str, "%d+%d", &A, &B);
		printf("%d\n", A+B);
	}
	return 0;
}
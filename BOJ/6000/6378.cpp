// baekjoon 6378 yechan
#include <bits/stdc++.h>
using namespace std;

char str[1111];
int N;

int main() {
	while (1) {
		scanf("%s", str);
		if (str[0] == '0') break;
		N = 0;
		for (int i=0; str[i]; i++) {
			N += str[i] - '0';
		}

		while (N >= 10) {
			int tmp = 0;
			while (N) {
				tmp += N%10;
				N /= 10;
			}
			N = tmp;
		}
		printf("%d\n", N);
	}
	return 0;
}
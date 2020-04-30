// baekjoon 5656 yechan
#include <bits/stdc++.h>
using namespace std;

int T, A, B;
char cmd[3];

int main() {
	while (1) {
		scanf("%d %s %d", &A, cmd, &B);
		if (cmd[0] == 'E') break;
		T++;
		printf("Case %d: ", T);
		if (cmd[0] == '>') {
			if (cmd[1] == '=') {
				puts(A >= B ? "true" : "false");
			} else {
				puts(A > B ? "true" : "false");
			}
		}
		if (cmd[0] == '<') {
			if (cmd[1] == '=') {
				puts(A <= B ? "true" : "false");
			} else {
				puts(A < B ? "true" : "false");
			}
		}
		if (cmd[0] == '=') {
				puts(A == B ? "true" : "false");
		}
		if (cmd[0] == '!') {
				puts(A != B ? "true" : "false");
		}
	}
}
// baekjoon 11723 yechan
#include <cstdio>
#include <cstring>
using namespace std;

int X, M, S;

int main() {
	char cmd[7];
	scanf("%d", &M);
	while (M--) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "add")) {
			scanf("%d", &X);
			S |= (1<<X);
		}
		if (!strcmp(cmd, "check")) {
			scanf("%d", &X);
			if (S & (1<<X)) puts("1");
			else puts("0");
		}
		if (!strcmp(cmd, "remove")) {
			scanf("%d", &X);
			S &= ~(1<<X);
		}
		if (!strcmp(cmd, "toggle")) {
			scanf("%d", &X);
			if (S>>X & 1) S &= ~(1<<X);
			else S |= (1<<X);
		}
		if (!strcmp(cmd, "all")) {
			S = (1<<21)-1;
		}
		if (!strcmp(cmd, "empty")) {
			S = 0;
		}
	}
	return 0;
}
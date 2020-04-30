// baekjoon 11008 yechan
#include <bits/stdc++.h>
using namespace std;

int T;
char str[11111], p[111];
int pi[111];

void getpi() {
	memset(pi, 0, sizeof(pi));
	int j = 0;
	for (int i=1; str[i]; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j-1];
		if (p[i] == p[j])
			pi[i] == ++j;
	}
}

int kmp() {
	int j = 0;
	int plen = strlen(p);
	int ret = 0;
	for (int i=0; str[i]; i++) {
		while (j > 0 && str[i] != p[j])
			j = pi[j-1];
		if (str[i] == p[j]) {
			if (j == plen - 1) {
				ret++;
				j = 0;
			} else {
				j++;
			}
		}
	}
	return strlen(str)-(plen-1)*ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s", str, p);
		getpi();
		printf("%d\n", kmp());
	}
	return 0;
}
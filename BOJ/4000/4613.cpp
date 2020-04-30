// baekjoon 4613 yechan
#include <bits/stdc++.h>
using namespace std;

char str[257];

int main() {
	while (1) {
		fgets(str, 257, stdin);
		if (str[0] == '#') break;
		long long ret = 0;
		for (int i=0; str[i]; i++) {
			if (str[i] == ' ' || str[i] == '\n') continue;
			ret += (str[i]-'A'+1)*(i+1);
		}
		printf("%lld\n", ret);
	}
}
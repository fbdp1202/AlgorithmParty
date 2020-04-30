// baekjoon 15904 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1111;

int pos;
char S[MAX_N];
const char str[5]="UCPC";

int main() {
	fgets(S, sizeof(S), stdin);
	bool ret = false;
	for (int i=0; S[i]; i++) {
		if (S[i] == str[pos]) {
			pos++;
			if (pos > 3) {
				ret = true;
			}
		}
	}
	if (ret) {
		puts("I love UCPC");
	} else {
		puts("I hate UCPC");
	}
	return 0;
}
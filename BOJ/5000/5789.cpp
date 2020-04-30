// baekjoon 5789 yechan
#include <bits/stdc++.h>
using namespace std;

int T;
char str[1111];

bool check() {
	int slen = (int)strlen(str);
	return str[slen/2-1] == str[slen/2];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		puts(check() ? "Do-it" : "Do-it-Not");
	}
}
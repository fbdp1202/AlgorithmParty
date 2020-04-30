// baekjoon 10174 yechan
#include <bits/stdc++.h>
using namespace std;

char str[1111];

char lower(char c) {
	if ('A' <= c && c <= 'Z') c = c-'A'+'a';
	return c;
}

bool check() {
	int slen = (int)strlen(str);
	if (str[slen-1] == '\n') slen--;
	for (int i=0; i<=slen/2; i++)
		if (lower(str[i]) != lower(str[slen-1-i]))
			return false;
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	getchar();
	while (T--) {
		fgets(str, 1111, stdin);
		puts(check() ? "Yes":"No");
	}
	return 0;
}
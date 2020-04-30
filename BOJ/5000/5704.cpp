// baekjoon 5704 yechan
#include <bits/stdc++.h>
using namespace std;

char str[222];
bool alpha[27];

int main() {
	while (1) {
		fgets(str, 222, stdin);
		if (str[0] == '*') break;
		fill(alpha, alpha+27, false);
		int cnt = 0;
		for (int i=0; str[i]; i++) {
			if (str[i] == ' ' || str[i] == '\n') continue;
			if (!alpha[str[i]-'a']) cnt++;
			alpha[str[i]-'a'] = true;
		}
		puts(cnt == 26 ? "Y" : "N");
	}
	return 0;
}
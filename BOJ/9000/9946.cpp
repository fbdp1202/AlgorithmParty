// baekjoon 9946 yechan
#include <bits/stdc++.h>
using namespace std;

char str1[1111];
char str2[1111];
int alpha[26];

bool check() {
	memset(alpha, 0, sizeof(alpha));
	if (strlen(str1) != strlen(str2)) return false;
	for (int i=0; str1[i]; i++)
		alpha[str1[i]-'a']++;
	for (int i=0; str2[i]; i++) {
		if (!alpha[str2[i]-'a']) return false;
		alpha[str2[i]-'a']--;
	}
	return true;
}

int main() {
	int T=1;
	while (1) {
		scanf("%s%s", str1, str2);
		if (str1[0] == 'E') break;
		printf("Case %d: %s\n", T, check() ? "same":"different");
		T++;
	}
}
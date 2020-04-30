// baekjoon 1371 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[5001];
int alpha[26];

int main()
{
	while (scanf("%s", str) != -1) {
		int i = 0;
		while (str[i]) {
			if (str[i] == ' ') { i++; continue; }
			if (str[i] == '\n') { i++; continue; }
			alpha[str[i]-'a']++;
			i++;
		}
	}

	int maxV = 0;
	for (int i=0; i<26; i++) {
		maxV = max(alpha[i], maxV);
	}
	for (int i=0; i<26; i++) {
		if (maxV == alpha[i]) {
			printf("%c", 'a'+i);
		}
	}

	return 0;
}
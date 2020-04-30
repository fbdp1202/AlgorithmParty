// baekjoon 2703 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T;
char str[1001];
char code[27];

int main() {
	scanf("%d", &T);
	while (T--) {
		getchar();
		fgets(str, 1001, stdin);
		scanf("%s", code);
		for (int i=0; str[i]; i++) {
			if (str[i] == '\n') continue;
			if (str[i] == ' ') printf(" ");
			else printf("%c", code[str[i]-'A']);
		}
		puts("");
	}
	return 0;
}
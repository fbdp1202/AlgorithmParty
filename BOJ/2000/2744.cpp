// baekjoon 2744 yechan
#include <cstdio>
char buf[101];

char convertChar(char c) {
	if('A' <= c && c <= 'Z') return c-'A'+'a';
	if('a' <= c && c <= 'z') return c-'a'+'A';
}

int main() {
	int i=0;
	scanf("%s", buf);
	while (buf[i]) {
		printf("%c", convertChar(buf[i]));
		i++;
	}
}
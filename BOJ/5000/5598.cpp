// baekjoon 5598 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[1001];

inline char decode(char c) { return (26 + c - 'A' - 3)%26 + 'A'; }

int main()
{
	scanf("%s", str);
	for (int i=0; str[i]; i++) {
		printf("%c", decode(str[i]));
	}
	puts("");
	return 0;
}
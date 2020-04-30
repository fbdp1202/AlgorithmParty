// baekjoon 2386 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[255];

int main()
{
	while (1) {
		char c;
		scanf(" %c", &c);
		if (c == '#') break;
		fgets(str, 255, stdin);

		int ret = 0;
		for (int i=0; str[i]; i++) {
			if ('A' <= str[i] && str[i] <= 'Z') str[i] = (str[i]-'A') + 'a';
			if (c == str[i]) ret++;
		}
		printf("%c %d\n", c, ret);
	}
	return 0;
}
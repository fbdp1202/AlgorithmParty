// baekjoon 1864 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[9];

int main()
{
	while (1) {
		scanf("%s", str);
		if (str[0] == '#') break;

		int ret = 0;
		for (int i=0; str[i]; i++) {
			ret *= 8;
			switch(str[i]) {
				case '-': ret += 0; break;
				case '\\': ret += 1; break;
				case '(': ret += 2; break;
				case '@': ret += 3; break;
				case '?': ret += 4; break;
				case '>': ret += 5; break;
				case '&': ret += 6; break;
				case '%': ret += 7; break;
				case '/': ret += -1; break;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
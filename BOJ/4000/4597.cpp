// baekjoon 4597 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[32];

int main()
{
	while (1) {
		scanf("%s", str);
		if (str[0] == '#') break;

		bool par = false;
		int cnt = 0;
		for (int i=0; str[i]; i++) {
			if (str[i] == 'e') continue;
			if (str[i] == 'o') {
				par = true;
				continue;
			}
			if (str[i] - '0') {
				cnt++;
			}
			printf("%c", str[i]);
		}
		printf("%d\n", (par+cnt)&1);
	}
	return 0;
}
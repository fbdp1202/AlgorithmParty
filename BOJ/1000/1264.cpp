// baekjoon 1264 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	while (1) {
		char str[266];
		fgets(str, 266, stdin);
		if (str[0] == '#') break;

		int ret = 0;
		for (int i=0; str[i]; i++) {
			switch(str[i]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U': ret++; break;
				default :;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
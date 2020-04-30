// baekjoon 11319 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char str[1001];

int main()
{
	scanf("%d", &N);
	fgets(str, 1001, stdin);
	while (N--) {
		fgets(str, 1001, stdin);
		int c=0, v=0;
		for (int i=0; str[i]; i++) {
			if (str[i] == ' ' || str[i] == '\n') continue;
			switch(str[i]) {
				case 'A':
				case 'a':
				case 'E':
				case 'e':
				case 'I':
				case 'i':
				case 'O':
				case 'o':
				case 'U':
				case 'u': v++; break;
				default: c++;
			}
		}
		printf("%d %d\n", c, v);
	}
	return 0;
}
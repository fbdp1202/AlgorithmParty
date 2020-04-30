// baekjoon 2857 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const char match[4] = "FBI";

int main()
{
	char str[14];
	int cnt = 0;
	for (int i=1; i<=5; i++) {
		scanf("%s", str);
		int here = 0;
		for (int j=0; str[j]; j++) {
			if (match[here] == str[j]) {
				here++;
				if (here == 3) {
					printf("%d ", i);
					cnt++;
					break;
				}
			} else {
				here = 0;
			}
		}
	}
	if (!cnt) {
		puts("HE GOT AWAY!");
	}
	return 0;
}
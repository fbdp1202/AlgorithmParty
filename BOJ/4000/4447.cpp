// baekjoon 4447 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char str[30];

int main()
{
	scanf("%d", &N);
	fgets(str, 30, stdin);
	while (N--) {
		fgets(str, 30, stdin);
		int bcnt=0, gcnt=0;
		for (int i=0; str[i]; i++) {
			if (str[i] == '\n') str[i] = '\0';
			if (str[i] == 'g' || str[i] == 'G') gcnt++;
			if (str[i] == 'b' || str[i] == 'B') bcnt++;
		}
		printf("%s is ", str);
		if (bcnt == gcnt) puts("NEUTRAL");
		else if (bcnt < gcnt) puts("GOOD");
		else puts("A BADDY");
	}
	return 0;
}
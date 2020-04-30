// baekjoon 2711 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char str[88];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %s", &N, str);
		for (int i=0; str[i]; i++) {
			if (i == N-1) continue;
			printf("%c", str[i]);
		}
		puts("");
	}
}
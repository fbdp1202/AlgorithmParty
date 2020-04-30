// baekjoon 17010 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N;
char c;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf(" %d %c", &N, &c);
		for (int i=0; i<N; i++)
			printf("%c", c);
		puts("");
	}
}
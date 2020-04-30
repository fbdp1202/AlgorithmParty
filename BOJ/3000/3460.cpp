// baekjoon 3460 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		int pos = 0;
		while (N) {
			if (N & 1) {
				printf("%d ", pos);
			}
			N >>= 1;
			pos++;
		}
		puts("");
	}
	return 0;
}
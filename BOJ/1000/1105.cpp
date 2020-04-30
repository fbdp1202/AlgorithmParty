// baekjoon 1150 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char L[11], R[11];
int Llen, Rlen, pos;

int main()
{
	scanf("%s %s", L, R);
	Llen = strlen(L), Rlen = strlen(R);
	if (Llen != Rlen) printf("0\n");
	else {
		int ret = 0;
		while (L[pos] && L[pos] == R[pos]) {
			if (L[pos] == '8') ret++;
			pos++;
		}
		printf("%d\n", ret);
	}
	return 0;
}
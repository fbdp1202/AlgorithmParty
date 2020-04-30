// baekjoon 11005 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, B, i;
char str[40];
int main() {
	scanf("%d %d", &N, &B);
	while (N) {
		int r = N%B;
		char c;
		if (r < 10) c = r + '0';
		else c = r-10 + 'A';
		str[i++]=c;
		N/=B;
	}
	for (i--; i>=0; i--)
		printf("%c", str[i]);
	return 0;
}
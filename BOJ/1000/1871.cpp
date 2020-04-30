// baekjoon 1871 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[10];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		int A=0, B=0;
		for (int i=0; i<3; i++) {
			A *= 26;
			A += (str[i] - 'A');
		}
		for (int i=4; i<8; i++) {
			B *= 10;
			B += (str[i] - '0');
		}
		if (abs(A-B) <= 100) {
			puts("nice");
		} else {
			puts("not nice");
		}
	}
	return 0;
}
// baekjoon 1550 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int ret;
char c;
int main() {
	while (scanf(" %c", &c) != -1) {
		ret <<= 4;
		if ('A'<= c && c <= 'F') c = c-'A'+10+'0';
		ret += c-'0';
	}
	printf("%d\n", ret);
	return 0;
}
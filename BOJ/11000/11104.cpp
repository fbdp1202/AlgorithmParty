// baekjoon 11104 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	char bits[25];
	while (N--) {
		scanf("%s", bits);
		int ret = 0;
		for (int i=0 ; bits[i]; i++) {
			ret *= 2;
			ret += bits[i] - '0';
		}
		printf("%d\n", ret);
	}
	return 0;
}
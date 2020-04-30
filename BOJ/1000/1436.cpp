// baekjoon 1436 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, ret;

int main() {
	scanf("%d", &N);
	for (int i=1; i<3000001; i++) {
		int check = i;
		int cnt = 0;
		while (check) {
			if (check % 10 == 6) cnt++;
			else cnt=0;
			check /= 10;
			if (cnt == 3) {
				ret++;
				if (ret == N) {
					return !printf("%d\n", i);
				}
				break;
			}
		}
	}
	return 0;
}
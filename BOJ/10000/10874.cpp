// baekjoon 10874 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, x, cnt;

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		cnt = 0;
		for (int j=1; j<=10; j++) {
			scanf("%d", &x);
			if ((j%5) != (x%5)) cnt++;
		}
		if (!cnt) printf("%d\n", i);
	}
	return 0;
}
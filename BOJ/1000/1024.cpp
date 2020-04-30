// baekjoon 1024 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, L;

int main() {
	scanf("%d%d", &N, &L);
	int flag = 0;
	for (int i=L; i<=100; i++) {
		if ( (N - i*(i+1)/2)%i == 0) {
			int bias = (N - i*(i+1)/2)/i;
			if (bias < -1) break;
			flag = 1;
			for (int j=1; j<=i; j++) {
				printf("%d ", bias+j);
			}
			break;
		}
	}

	if (!flag) puts("-1");
	return 0;
}
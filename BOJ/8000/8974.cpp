// baekjoon 8974 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A, B;

int main() {
	scanf("%d%d", &A, &B);

	int value = 1;
	int cnt = 0;
	int ret = 0;
	for (int i=1; i<=B; i++) {
		if (A <= i) ret += value;
		if (++cnt == value) cnt=0,value++;
	}
	printf("%d\n", ret);
	return 0;
}
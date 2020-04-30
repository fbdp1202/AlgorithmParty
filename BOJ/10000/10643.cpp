// baekjoon 10643 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int num[8];
	int maxValue=0;

	for (int i=0; i<8; i++)
		scanf("%d", &num[i]);

	for (int i=0; i<8; i++) {
		int tmp = 0;
		for (int j=i; j<i+4; j++)
			tmp += num[j%8];
		maxValue = max(maxValue, tmp);
	}
	printf("%d", maxValue);
	return 0;
}
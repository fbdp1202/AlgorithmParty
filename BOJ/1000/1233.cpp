// baekjoon 1233 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int S1, S2, S3;
int cnt[88];

int main() {
	scanf("%d%d%d", &S1, &S2, &S3);
	for (int i=1; i<=S1; i++)
		for (int j=1; j<=S2; j++)
			for (int k=1; k<=S3; k++)
				cnt[i+j+k]++;

	int maxV=0;
	int maxCnt=0;
	for (int i=1; i<88; i++) {
		if (maxCnt < cnt[i]) {
			maxV = i;
			maxCnt = cnt[i];
		}
	}
	printf("%d\n", maxV);
	return 0;
}
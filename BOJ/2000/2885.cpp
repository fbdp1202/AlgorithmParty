// baekjoon 2885 yechan
#include <bits/stdc++.h>
using namespace std;

int K;

int main() {
	scanf("%d", &K);
	int cnt=0;
	int mCnt=1e9;
	while ((1<<cnt) < K) {
		if ((K>>cnt) & 1) mCnt=min(mCnt, cnt);
		cnt++;
	}
	if ((K>>cnt) & 1) mCnt=min(mCnt, cnt);
	printf("%d %d\n", (1<<cnt), cnt-mCnt);

	return 0;
}
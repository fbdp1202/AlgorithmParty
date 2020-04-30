// baekjoon 2135 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=201;

char str[MAX_N];
int dp[MAX_N][MAX_N];

int digit(int num) {
	if (num == 0) return 1;
	int ret = 0;
	while (num) {
		num/=10;
		ret++;
	}
	return ret;
}

int RLE(int start, int end) {
	int &ret = dp[start][end];
	if (ret != -1) return ret;
	if (end - start <= 4) return ret = (end-start);
	ret = end - start;
	for (int patLen=1; start+patLen < end; patLen++) {
		int minPatLen = min(patLen, RLE(start, start+patLen));
		ret = min(ret, minPatLen + RLE(start+patLen, end));
		for (int repeat=2; start+repeat*patLen<=end; repeat++) {
			bool flag = true;
			for (int k=0; k<patLen; k++) {
				if (str[start+k] != str[start+(repeat-1)*patLen+k]) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
			ret = min(ret, min(minPatLen*repeat, digit(repeat)+2+minPatLen)+RLE(start+patLen*repeat, end));
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s", &str);
	printf("%d\n", RLE(0, strlen(str)));
	return 0;
}
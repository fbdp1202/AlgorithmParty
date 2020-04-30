// baekjoon 1509 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 2502;

char str[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
	scanf("%s", &str);
	int slen = strlen(str);
	printf("strlen: %d\n", slen);
	for (int i=1; i<slen+1; i++) {
		for (int j=1; j<slen+1; j++) {
			if (str[j-1] == str[slen-i]) dp[i][j] = dp[i-1][j-1] + 1;
		}
	}
	printf("   ");
	for (int i=1; i<slen+1; i++)
		printf("%c ", str[i-1]);
	puts("");
	for (int i=1; i<slen+1; i++) {
		printf("%c: ", str[slen-i]);
		for (int j=1; j<slen+1; j++) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}
	printf("   ");
	for (int j=1; j<slen+1; j++) {
		int ret = 0;
		for (int i=1; i<slen+1; i++) {
			ret = max(ret, dp[i][j]);
		}
		printf("%d ", ret);
	}
	return 0;
}
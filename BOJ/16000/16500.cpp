// baekjoon 16500 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;
const int MAX_L=201;

int N;
char A[MAX_L];
char S[MAX_N][MAX_L];

bool dp[MAX_L];

int main() {
	scanf("%s", A);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", S[i]);

	dp[0]=true;
	for (int i=0; i<strlen(A); i++) {
		if (!dp[i]) continue;
		for (int j=0; j<N; j++) {
			bool flag=true;
			for (int k=0; k<strlen(S[j]); k++) {
				if (A[i+k] != S[j][k]) {
					flag=false;
					break;
				}
			}
			if (!flag) continue;
			dp[i+strlen(S[j])] = true;
		}
	}
	puts((dp[strlen(A)] ? "1" : "0"));
	return 0;
}
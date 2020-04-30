// baekjoon 9252 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_INPUT_SIZE 1001

char A[MAX_INPUT_SIZE], B[MAX_INPUT_SIZE];
int N, dp[MAX_INPUT_SIZE][MAX_INPUT_SIZE];
char source[MAX_INPUT_SIZE];

int main()
{
	scanf("%s %s", A, B);
	int AL = strlen(A); int BL = strlen(B);
	for(int i=0; i<AL; i++){
		for(int j=0; j<BL; j++){
			int tmp = 0;
			if(A[i] == B[j]){
				tmp = max(tmp, dp[i][j]+1);
				// source[i+1][j+1] =
			}
			tmp = max(tmp, max(dp[i][j+1], dp[i+1][j]));
			dp[i+1][j+1] = tmp;
		}
	}


	printf("%d\n", dp[AL][BL]);
	if(dp[AL][BL]){
		int i=AL, j=BL, sp = dp[AL][BL];
		source[sp] = '\0';
		while(i>=1 && j>=1){
			if(dp[i-1][j] == dp[i][j]){
				i--; continue;
			}
			if(dp[i][j-1] == dp[i][j]){
				j--; continue;
			}
			if(dp[i-1][j-1] == dp[i][j]-1){
				source[--sp] = A[i-1];
				i--; j--; continue;
			}
		}
		printf("%s", source);
	}
	return 0;
}
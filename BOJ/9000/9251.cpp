// baekjoon 9251 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_LEN 1001

char A[MAX_LEN], B[MAX_LEN];
int LCS[MAX_LEN][MAX_LEN];

int main()
{
	scanf("%s", A);
	scanf("%s", B);
	int SLENA = strlen(A);
	int SLENB = strlen(B);

	for(int i = 0; i < SLENA; i++){
		for(int j = 0; j < SLENB; j++){
			if(A[i] == B[j])
				LCS[i+1][j+1] = LCS[i][j] + 1;
			else
				LCS[i+1][j+1] = max(LCS[i+1][j], LCS[i][j+1]);
		}
	}

	printf("%d", LCS[SLENA][SLENB]);
}
// baekjoon 11066 yechan
#include <cstdio>
#include <algorithm>
#define MAX_K 501
#define INF 987654321
using namespace std;
int T, K, file[MAX_K];
int dp[MAX_K][MAX_K]; // i~j 까지 합.
int s[MAX_K];

int main()
{
	scanf("%d", &T);
	for(int i=0; i<T; i++)
	{
		scanf("%d", &K);
		for(int j=0; j<K; j++)
			scanf("%d", &file[j]);

		s[1] = file[0];
		for(int j=1; j<K; j++) s[j+1] = s[j]+file[j];
		for(int j=0; j<K-1; j++) dp[j][j+1] = file[j]+file[j+1];
		for(int g=2; g<K; g++){
			for(int j=0; j+g<K; j++){
				dp[j][j+g] = INF;
				for(int z=j; z<j+g; z++){
					dp[j][j+g] = min(dp[j][z]+dp[z+1][j+g]+s[j+g+1]-s[j], dp[j][j+g]);
				}
			}
		}
		printf("%d\n", dp[0][K-1]);
	}
	return 0;
}
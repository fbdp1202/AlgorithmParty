// baekjoon 2240 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_T 1001
#define MAX_W 31

int T, W, tree[MAX_T], dp[MAX_W][2];

int main()
{
	scanf("%d %d", &T, &W);
	for ( int i=1; i<=T; i++ )	scanf("%d", &tree[i]);

	for ( int i=1; i<=T; i++ ) {
		if ( tree[i] == 1 )	dp[0][0]++;

		for ( int j=1; j<=W; j++ ) {
			dp[j][0] = max( dp[j][0], dp[j-1][1] );
			dp[j][1] = max( dp[j][1], dp[j-1][0] );
			if ( tree[i] == 1 ) 	dp[j][0]++;
			else 			 		dp[j][1]++;
		}
	}

	int max_fruit = 0;
	for ( int j=0; j<=W; j++ ) {
		for ( int i=0; i<2; i++ ) {
			max_fruit = max( max_fruit, dp[j][i] );
		}
	}

	printf("%d", max_fruit);
	return 0;
}
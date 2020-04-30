// baekjoon 2011 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_L 5001
#define DIV_NUM 1000000
char password[MAX_L];
int dp[MAX_L];

int main()
{
	scanf("%s", password);
	int plen = strlen(password);

	if(password[0] =='0'){
		printf("0"); return 0;
	}
	dp[0] = 1;
	dp[1] = 1;

	for(int i=1; i<plen; i++){
		if(password[i] == '0'){
			if(password[i-1] == '1' || password[i-1] == '2')
				dp[i+1] += dp[i-1];
			else{
				printf("0"); return 0;
			}
		}
		else{
			dp[i+1] += dp[i];
			if(password[i-1] =='1')
				dp[i+1] += dp[i-1];
			else if(password[i-1] == '2' && password[i] <= '6')
				dp[i+1] += dp[i-1];
		}
		dp[i+1] = dp[i+1]%DIV_NUM;
	}

	printf("%d", dp[plen]);
}
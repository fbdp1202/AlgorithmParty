#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[1000001];
ll sum[1000001];

ll dfs(int here) {
    ll &ret = dp[here];
    if (ret != -1) return ret;
    if (here % 2) ret=dfs(here+1)+1;
    else ret=dfs(here/2)+1;
}

int main(int argc, char** argv)
{
    memset(dp, -1, sizeof(dp));
    dp[1]=0;
 	long long ret=0;
    for (int i=2; i<=1000000; i++) {
        ret += dfs(i);
        sum[i]=ret;
    }
    
 	int T, test_case;
 	scanf("%d", &T);
 	int N1, N2;
 	for (int t=1; t<=T; t++){
 	    printf("Case #%d\n", t);
 	    scanf("%d%d", &N1, &N2);
 	    printf("%lld\n", sum[N2]-sum[N1-1]);
 	}
	return 0;//Your program should return 0 on normal termination.
}
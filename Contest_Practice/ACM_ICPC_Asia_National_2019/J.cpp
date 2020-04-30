#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N=10001;
const ll MAX_INF=(1LL<<62);

ll sum[MAX_N];
ll dp[MAX_N];
P data[MAX_N];

int dfs(int here) {}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i=1; i<N; i++) {
		int x;
		scanf("%d", &x);
		sum[i] = sum[i-1] + x;
	}

	for (int i=0; i<N-1; i++) {
		int u, v;
		scanf("%d%d", &data[i].first, &data[i].second);
	}

	dfs(0);
	return 0;
}
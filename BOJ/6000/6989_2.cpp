// baekjoon 6989 yechan
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std; 

typedef pair<int,int> P;
typedef pair<int, P> PP;

const int MAX_N=151;
const int MAX_V=1132500; // 최대 점수

int N, K;
int data[MAX_N];
int dp[MAX_V+2];
set<PP> s;

void dfs(int here, int sum, int inc) {
	dp[sum] = true;
	if (here == N) return;
	if (s.count(PP(here, P(sum, inc)))) return;
	s.insert(PP(here, P(sum, inc)));

	dfs(here+1, sum, 0);
	dfs(here+1, sum+inc+data[here], inc+data[here]);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);

	scanf("%d", &K);
	if (K > MAX_V) return !printf("%d\n", K);

	dfs(0, 0, 0);

	int cnt = 0;
	for (int i=0; i<200; i++) {
		if (dp[i]) {
			printf("%d\n", i);
			cnt++;
		}
	}
	printf("cnt: %d\n", cnt);

	for (int i=K; ; i++)
		if (!dp[i])
			return !printf("%d\n", i);
	return 0;
}
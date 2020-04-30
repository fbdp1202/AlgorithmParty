// baekjoon 13305 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100001
typedef long long ll;

int N, curr, e[MAX_N];
ll length, rst, cost[MAX_N];
int i;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N-1; i++)
		scanf("%d", &e[i]);
	for (int i=0; i<N; i++)
		scanf("%d", &cost[i]);

	while (i < N) {
		curr = cost[i];
		length = e[i];
		while (curr < cost[++i]){
			length += e[i];
		}
		rst += length*curr;
	}
	printf("%lld\n", rst);
	return 0;
}
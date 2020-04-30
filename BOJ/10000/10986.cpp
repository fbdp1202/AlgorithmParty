// baekjoon 10986 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_M 1000
#define f(n) ((n)*(n+1)/2)
typedef long long ll;

int N, M;
ll curr, x, result, div_pos[MAX_M];

int main() {
	scanf("%d%d", &N, &M);
	div_pos[0]++;
	for (int i=0; i<N; i++) {
		scanf("%lld", &x);
		curr = (curr + x) % M;
		div_pos[curr]++;
	}

	for (int i=0; i<M; i++)
		if (div_pos[i])
			result += f(div_pos[i]-1);

	printf("%lld\n", result);
	return 0;
}
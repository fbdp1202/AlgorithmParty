// baekjoon 2004 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, M;
int a, b, c, a1, b1, c1;

int main() {
	scanf("%lld %lld", &N, &M);
	for (ll r=5; r<=N; r*=5) 	a+=N/r;
	for (ll r=2; r<=N; r*=2) 	a1+=N/r;

	for (ll r=5; r<=N-M; r*=5) 	b+=(N-M)/r;
	for (ll r=2; r<=N; r*=2) 	b1+=(N-M)/r;

	for (ll r=5; r<=M; r*=5) 	c+=M/r;
	for (ll r=2; r<=N; r*=2) 	c1+=M/r;

	printf("%d\n", min(a-b-c, a1-b1-c1));
	return 0;
}
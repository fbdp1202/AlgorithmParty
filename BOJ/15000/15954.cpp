// baekjoon 15954 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 500
#define INF 1e9
typedef long long ll;
int N, K;
ll x, meanSum[MAX_N], divSum[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
	scanf("%lld", &x);
	meanSum[0] = x; divSum[0] = x*x;
	for (int i=1; i<N; i++) {
		scanf("%lld", &x);
		meanSum[i] = meanSum[i-1] + x;
		divSum[i] = divSum[i-1] + x*x
	}

	double ans = INF;
	for (int l=K; l<N; l++) {
		for (int pos=K; pos<N; pos++) {
			
		}
	}
	return 0;
}
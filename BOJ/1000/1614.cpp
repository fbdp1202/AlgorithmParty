// baekjoon 1614 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
ll ret, K;

ll fun(ll x, int a, int b) {
	return 1LL*a*x + b;
}

int main() {
	scanf("%d%d", &N, &K);

	if (K){
		switch(N) {
			case 1: ret = fun(K, 8, 1); break;
			case 2:
				if (K & 1) 	{ ret = fun((K+1)/2-1, 8, 8); break; }
				else 		{ ret = fun(K/2, 8, 2); break; }
			case 3: ret = fun(K, 4, 3); break;
			case 4:
				if (K & 1) 	{ ret = fun((K+1)/2-1, 8, 6); break; } 
				else 		{ ret = fun(K/2, 8, 4); break; }
			case 5: ret = fun(K, 8, 5); break;
		}
	} else ret = N;
	printf("%lld\n", ret-1);
	return 0;
}
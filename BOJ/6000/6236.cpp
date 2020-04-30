// baekjoon 6236 yechan
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000
typedef long long ll;

int N, M, data[MAX_N];
ll lo, mid, hi, result;

bool CheckLession(ll blen) {
	ll tmp=0;
	int lesson=1;
	for (int i = 0; i < N; i++) {
		if (data[i] > blen)
			return false;
		if (tmp + data[i] > blen){
			tmp=data[i], lesson++;
		}
		else{
			tmp += data[i];
		}
	}
	return (lesson <= M);
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	
	hi = result = 1e10;

	while (lo <= hi) {
		mid = (ll)(lo + hi) / 2;
		if (CheckLession(mid)){
			hi = mid - 1; result = min(result, mid);
		}
		else{
			lo = mid + 1;
		}
	}
	printf("%lld\n", result);
	return 0;
}
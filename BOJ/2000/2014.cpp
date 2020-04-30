// baekjoon 2014 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;

int K, N, primes[100];
priority_queue<ll, vector<ll>, greater<ll>> PQ;

int main() {
	scanf("%d %d", &K, &N);

	for (int i=0; i<K; i++) {
		scanf("%d", &primes[i]);
		PQ.push(primes[i]);
	}

	for (int i=0; i<N-1; i++) {
		ll head = PQ.top();
		for (int j=0; j<K; j++) {
			ll tmp = head*primes[j];
			PQ.push(tmp);
			if (head % primes[j] == 0) break;
		}
		PQ.pop();
	}

	printf("%d\n", PQ.top());
	return 0;
}
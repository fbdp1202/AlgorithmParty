// baekjoon 1644 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, result, sum, s, e;
vector<int> primes;
vector<bool> check;

int main() {
	scanf("%d", &n);
	check.resize(n + 1, true);
	for (int i=2; i*i <= n; i++) {
		if (!check[i]) continue;
		for (int j=i*i; j<=n; j+=i) {
			check[j]=false;
		}
	}
	for (int i=2; i<=n; i++)
		if (check[i])
			primes.push_back(i);

	while (1) {
		if (sum >= n) {
			sum -= primes[s++];
		} else if (e == primes.size()) {
			break;
		} else {
			sum += primes[e++];
		}

		if (sum == n) result++;
	}
	printf("%d\n", result);
}
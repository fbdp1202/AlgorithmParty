// baekjoon 4276 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll subsum[12] = { 1, 9, 180, 2700, 36000, 450000, 5400000, 63000000, 720000000, 8100000000, 90000000000, 990000000000};
const ll sum[12] = { 1, 10, 190, 2890, 38890, 488890, 5888890, 68888890, 788888890, 8888888890, 98888888890, 108888888890};

ll pow(int n, int p) {
	ll result = 1;
	for (int i = 0; i < p; i++)
		result *= n;

	return result;
}

ll countZero(ll n) {
	ll result = 0;
	ll temp = n;
	int digit = 0;

	if (n < 0) return 0;

	while (temp > 0) {
		if (temp % 10) result += pow(10, digit);
		else  result += n%pow(10, digit) + 1;

		result += subsum[digit++] / 9 * (temp % 10);
		temp /= 10;
	}

	if (digit >= 2) result -= (subsum[digit - 1] / 9 - sum[digit - 2]) + pow(10, digit - 1);

	return result ? result : 1;
}
int main() {
	int T;
	ll a, b;
	while (scanf("%lld%lld", &a, &b)) {
		if (a < 0) break;
		printf("%lld\n", countZero(b) - countZero(a - 1));
	}

	return 0;
}
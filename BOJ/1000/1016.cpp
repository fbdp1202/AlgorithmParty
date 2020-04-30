// baekjoon 1016 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

LL a, b;
bool visited[1000001];

int main() {
	scanf("%lld %lld", &a, &b);

	for (LL i=2; i*i<=b; i++) {
		LL start = a / (i*i);
		if (start*i*i != a) start++;
		for (LL j=start; i*i*j<=b; j++) {
			visited[i*i*j-a] = true;
		}
	}

	int result = 0;
	for (int i=0; i<=(b-a); i++)
		if(!visited[i]) result++;

	printf("%d", result);
	return 0;
}
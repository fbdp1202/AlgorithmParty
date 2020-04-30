// baekjoon 6588 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1000001;
int N;
bool isprime[MAX_N];

int main() {
	isprime[1]=true;
	for (int i=2; i*i<=MAX_N; i++)
		if (!isprime[i])
			for (int j=i*i; j<=MAX_N; j+=i)
				isprime[j] = true;

	while (1) {
		int x;
		scanf("%d", &x);
		if (!x) return 0;
		for (int i=2; i<=x/2; i++) {
			if (!isprime[i] && !isprime[x-i]) {
				printf("%d = %d + %d\n", x, i, x-i);
				break;
			}
		}
	}
	return 0;
}
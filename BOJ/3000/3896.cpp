// baekjoon 3896 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1299710;

int T, N;
bool isprime[MAX_N];

int main() {
	isprime[1]=true;
	for (int i=2; i*i<MAX_N; i++)
		if (!isprime[i])
			for (int j=i*i; j<MAX_N; j+=i)
				isprime[j]=true;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		if (!isprime[N]) {
			puts("0");
			continue;
		}
		int cnt = 1;
		for (int i=N-1; i>= 0; i--) {
			if (!isprime[i]) break;
			cnt++;
		}
		for (int i=N+1; i<MAX_N; i++) {
			if (!isprime[i]) break;
			cnt++;
		}
		printf("%d\n", cnt+1);

	}
	return 0;
}
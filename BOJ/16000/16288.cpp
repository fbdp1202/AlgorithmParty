// baekjoon 16288 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int N, K;
int seq[MAX_N];
int passport[MAX_N];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		scanf("%d", &seq[i]);

	fill(passport, passport+K, 200);

	for (int i=N-1; i>=0; i--) {
		bool match=false;
		for (int j=0; j<K; j++) {
			if (passport[j] > seq[i]) {
				passport[j] = seq[i];
				match=true;
				break;
			}
		}
		if (!match) return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
}
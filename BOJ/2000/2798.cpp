// baekjoon 2798 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=101;

int N, M, card[MAXN], ret, tmp;

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%d", &card[i]);

	for (int i=0; i<N; i++) {
		tmp+=card[i];
		for (int j=i+1; j<N; j++) {
			tmp+=card[j];
			for (int k=j+1; k<N; ++k) {
				tmp+=card[k];
				if (tmp <= M) ret=max(ret, tmp);
				tmp-=card[k];
			}
			tmp-=card[j];
		}
		tmp-=card[i];
	}
	printf("%d\n", ret);
	return 0;
}
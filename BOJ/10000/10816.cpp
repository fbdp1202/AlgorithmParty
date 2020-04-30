// baekjoon 10816 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 500001;

int N, M, x, data[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	sort(data, data+N);

	scanf("%d", &M);
	for (int i=0; i<M; i++) {
		scanf("%d", &x);
		printf("%d ", lower_bound(data, data+N, x+1) - lower_bound(data, data+N, x));
	}
	puts("");
	return 0;
}
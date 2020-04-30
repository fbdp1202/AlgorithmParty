// postech hw01-B fbdp1202(yechan)
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1001;

int t, N, list[MAX_N];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d", &list[i]);
		sort(list, list+N);
		for (int i=0; i<N; i++)
			printf("%d ", list[i]);
		puts("");
	}
	return 0;
}
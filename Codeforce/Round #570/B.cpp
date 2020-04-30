#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 101;
int q, n, k;
int arr[MAX_N];
int maxV, minV;

int main() {
	scanf("%d", &q);
	while (q--) {
		maxV = 1e9;
		minV = 0;
		scanf("%d%d", &n,&k);
		for (int i=0; i<n; i++) {
			int x;
			scanf("%d", &x);
			maxV = min(maxV, x+k);
			minV = max(minV, max(0, x-k));
		}
		if (minV > maxV) puts("-1");
		else printf("%d\n", maxV);
	}
	return 0;
}
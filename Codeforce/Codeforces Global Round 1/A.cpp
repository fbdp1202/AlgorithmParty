#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
int b, k, a[MAX_N];

int main() {
	scanf("%d %d", &b, &k);
	for (int i=0; i<k; i++)
		scanf("%d", &a[i]);

	int ret = 0;
	for (int i=0; i<k; i++) {
		if (a[i]%2 == 0) continue;
		if (i != k-1 && b%2 == 0) continue;
		ret++;
	}
	if (ret%2 == 0) printf("even\n");
	else printf("odd\n");
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1000001;

int n, m;
int data[MAX_N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) {
		int x; scanf("%d", &x);
		data[x]++;
	}

	for (int i=1; i<=m; i++) {
		printf("%d ", data[i]);
	}
	puts("");
	return 0;
}
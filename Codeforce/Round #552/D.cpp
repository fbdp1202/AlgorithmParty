#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=200001;

int N, a, b;
int bt[MAX_N];

int main() {
	scanf("%d%d%d", &N, &a, &b);
	int i=0;
	for (i=0; i<N; i++) {
		scanf("%d", &bt[i]);
	}
	return 0;
}
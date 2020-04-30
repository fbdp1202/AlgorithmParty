#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 200001;
int N;
int arr[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[N-i-1]);

	int minV=arr[0];
	long long ret = arr[0];
	for (int i=1; i<N; i++) {
		minV = max(0, min(minV-1, arr[i]));
		if (!minV) break;
		ret += minV;
	}
	printf("%lld\n", ret);
	return 0;
}
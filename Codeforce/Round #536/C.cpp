// codeconferce C yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define SQ(x) ((x)*(x))
const int MAX_N = 300001;

int N, data[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	sort(data, data+N);

	long long ret = 0;
	for (int i=0; i<N/2; i++)
		ret += SQ(data[i]+data[N-i-1]);
	printf("%lld\n", ret);
	return 0;
}
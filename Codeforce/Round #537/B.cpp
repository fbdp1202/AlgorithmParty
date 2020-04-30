// Round 537 B.cpp yechan
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX_N = 100001;

typedef long long ll;
int N, K, M;
ll data[MAX_N];

int main() {
	scanf("%d%d%d", &N, &K, &M);
	for (int i=0; i<N; i++)
		scanf("%lld", &data[i]);
	sort(data, data+N, greater<int>());

	for (int i=1; i<N; i++)
		data[i] = data[i]+data[i-1];

	double maxV = 0;
	for (int i=N-1; i>=0; i--) {
		maxV = max(maxV, (double)(min(M-(N-1-i), K*(i+1))+data[i])/(double)(i+1.f));
		if (M-(N-1-i) == 0) break;
	}
	printf("%.20f", maxV);
	return 0;
}
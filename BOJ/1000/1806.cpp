// baekjoon 1806 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, s, e, sum, ret=100001;
vector<int> v;

int main() {
	scanf("%d%d", &N, &M);
	v.resize(N);
	for (int i=0; i<N; i++)
		scanf("%d", &v[i]);

	while (1) {
		if (sum >= M) {
			ret = min(ret, e-s);
			sum -= v[s++];
		} else if (e == v.size()) {
			break;
		} else {
			sum += v[e++];
		}
	}
	if (ret == 100001) ret = 0;
	printf("%d\n", ret);
	return 0;
}
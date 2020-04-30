// baekjoon 1350 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll num;
int N, C, data[1000];
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	scanf("%d", &C);
	for (int i=0; i<N; i++) {
		if (data[i] % C == 0)
			num += data[i] / C;
		else 
			num += data[i] / C + 1;
	}
	printf("%lld\n", num*(ll)(C));
	return 0;
}
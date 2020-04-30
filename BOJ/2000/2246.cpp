// baekjoon 2246 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=10000;
struct Condo{
	int D, C;
	Condo(){}
	Condo(int D, int C):D(D), C(C){}
	bool operator<(const Condo& o) {
		if (D == o.D) return C < o.C;
		return D < o.D;
	}
};

int N, cnt;
Condo condo[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &condo[i].D, &condo[i].C);
	sort(condo, condo+N);
	int maxV=10001;
	for (int i=0; i<N; i++) {
		if (condo[i].C < maxV) {
			maxV=condo[i].C;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
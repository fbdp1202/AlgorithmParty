// baekjoon 1920 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100000
int N, M, S, lo, hi, mid, flag;

int main() {
	scanf("%d", &N);
	int *d = new int[N];
	for (int i=0; i<N; i++) scanf("%d", &d[i]);
	scanf("%d", &M);
	sort(d, d+N);
	for(int i=0; i<M; i++) {
		lo=0, hi=N, flag=0;
		scanf("%d", &S);
		while (lo < hi) {
			mid = (lo+hi)/2;
			if 		(d[mid]==S){ flag=1; break; }
			else if (d[mid]<S)	lo = mid+1;
			else 				hi = mid;
		}
		printf("%d\n", flag);
	}
	return 0;
}
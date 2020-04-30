// baekjoon 1292 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

long long data[MAX_N*MAX_N];

int main() 
{
	int A, B;
	scanf("%d%d", &A, &B);
	int cnt = 0;
	int here = 1;
	for (int i=1; i<=B; i++) {
		data[i] += data[i-1] + here;
		cnt++;
		if (here == cnt) {
			cnt = 0;
			here++;
		}
	}
	printf("%lld\n", data[B]-data[A-1]);
	return 0;
}

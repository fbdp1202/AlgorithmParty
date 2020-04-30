// baekjoon 1188 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, cnt;

int main() {
	scanf("%d%d", &N, &M);
	while (N%M) {
		N%=M;
		cnt+=N;
		M-=N;
	}
	printf("%d\n", cnt);
	return 0;
}
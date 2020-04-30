// baekjoon 1107 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, tmp, remote[10];

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i=0; i<M; i++)
		scanf("%d", &tmp), remote[tmp]++;

	return 0;
}
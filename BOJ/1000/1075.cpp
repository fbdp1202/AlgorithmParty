// baekjoon 1075 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, F, rst;

int main() {
	scanf("%d %d", &N, &F);
	N = (N/100)*100;
	printf("%02d", F-1-(N-1)%F);
	return 0;
}
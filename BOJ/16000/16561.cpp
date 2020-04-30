// baekjoon 16561 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	N/=3; N-=2;
	printf("%d\n",(N*(N+1))/2);
	return 0;
}
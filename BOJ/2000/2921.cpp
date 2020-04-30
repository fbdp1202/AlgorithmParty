// baekjoon 2921 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N; 

int main() {
	scanf("%d", &N);
	printf("%d", (N*(N+1)*(N+2))/2);
	return 0;
}
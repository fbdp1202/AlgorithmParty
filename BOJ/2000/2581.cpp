// baekjoon 2581 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int M, N, rst, minb;
bool prime[10001];

int main() {
	scanf("%d %d", &M, &N);
	prime[1] = true;
	for(int i=2; i <= 10000; i++) {
		if(prime[i]) continue;
		for(int j=i+i; j<=10000; j+=i) {
			prime[j]=true;
		}
	}
	for(int i=M; i<=N; i++) {
		if(!prime[i]) {
			if(!rst) minb=i;
			rst+=i;
		}
	}
	if(!rst)	printf("-1");
	else 		printf("%d\n%d", rst,minb);
}
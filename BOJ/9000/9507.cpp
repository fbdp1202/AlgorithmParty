// baekjoon 9507 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 68
typedef long long unsigned LL;
int t, n;
LL koong[MAX_N];

int main(){
	koong[0] = 1; koong[1] = 1;
	koong[2] = 2; koong[3] = 4;
	for(int i=4; i<MAX_N; i++){
		koong[i] = koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4];
	}

	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		printf("%lld\n", koong[n]);
	}
}
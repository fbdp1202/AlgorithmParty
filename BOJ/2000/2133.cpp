// baekjoon 2133 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 30;

int N, result;
// 0: 평평 			 1: upper row bar,
// 2: below row bar
int tile[31];

int main()
{
	scanf("%d", &N);
	if(N%2 == 1){ printf("0"); return 0; }
	tile[0] = 1;
	tile[2] = 3;
	for(int i=4; i<N+1; i+=2){
		for(int j=2; j <= i; j+= 2){
			int standard = (j == 2) ? 3 : 2;
			tile[i] += standard * tile[i-j];
		}
	}
	printf("%d", tile[N]);
	return 0;
}
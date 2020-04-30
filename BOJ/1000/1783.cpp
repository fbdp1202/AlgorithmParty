// baekjoon 1783 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, tmp=1;
	scanf("%d %d", &N, &M);
	if(N == 1){ printf("1"); return 0; }
	if(N == 2){
		tmp+= min((M-1)/2, 3);
	}
	if(N >= 3){
		if(M < 7){
			tmp += min(M-1,3);
		}else{
			tmp += 4+(M-7);
		}
	}
	printf("%d", tmp);
}
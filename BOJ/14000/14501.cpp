// baekjoon 14501 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, money[15], day[15];

int calMoney(int d){
	if(d >= N) return 0;
	int tmp=0;
	if(d + day[d] <= N){
		tmp = calMoney(d+day[d])+money[d];
	}
	tmp=max(tmp, calMoney(d+1));
	return tmp;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &day[i], &money[i]);
	int result = calMoney(0);
	printf("%d", result);
	return 0;
}
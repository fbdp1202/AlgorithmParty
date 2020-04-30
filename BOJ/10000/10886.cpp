// baekjoon 10886 yechan
#include <cstdio>
using namespace std;
int N, cnt, tmp;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &tmp);
		if(tmp) cnt++;
	}
	if(cnt>N/2) printf("Junhee is cute!");
	else 		printf("Junhee is not cute!");
	return 0;
}
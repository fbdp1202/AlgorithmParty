// baekjoon 14740 yechan
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 500000
typedef long long LL;

LL source[MAX_N];
bool stop[MAX_N];

int main()
{
	int N, c_stop = 0;
	LL tmp;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &source[i]);
	}
	for(int i = 0; i < N; i++){
		scanf("%lld", &tmp);
		source[i] -= tmp;
	}

	long long min_v;
	min_v = max((LL)987654321, source[N-1]);
	for(int i = N-1; i >= 0; i--){
		min_v = min(min_v + source[i], source[i]);
		if(min_v < 0 && !stop[i]){
			stop[i] = true;
			c_stop++;
		}
	}
	for(int i = N-1; i >= 0; i--){
		min_v = min(min_v + source[i], source[i]);
		if(min_v < 0 && !stop[i]){
			stop[i] = true;
			c_stop++;
		}
	}
	printf("%d", N-c_stop);
}
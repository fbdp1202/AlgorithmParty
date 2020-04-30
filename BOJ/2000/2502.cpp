// baekjoon 2502 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_D=31;
typedef long long ll;

int D, K;
ll fibo[31];

int main() {
	fibo[0]=fibo[1]=1;
	for (int i=2; i<MAX_D; i++)
		fibo[i] = fibo[i-1]+fibo[i-2];
	scanf("%d%d", &D, &K);
	for (int i=0; i<K; i++) {
		if (!((K-i*fibo[D-3])%fibo[D-2])){
			printf("%d\n%d\n",i,(K-i*fibo[D-3])/fibo[D-2]);
			break;
		}
	}

	return 0;
}
// baekjoon 2293 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MAX_K 10000

int n, k;
int money[MAX_N];
int value[MAX_K+1];

int main(){
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d",&money[i]);

	sort(money, money+n);
	value[0]=1;
	for(int i=0; i<n; i++){
		for(int j=money[i]; j<k+1; j++){
			value[j] += value[j-money[i]];
		}
	}
	printf("%d",value[k]);
}
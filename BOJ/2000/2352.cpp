// baekjoon 2352 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 40000

int n;
int port[MAX_N+1];
int cache[MAX_N+1];
int length;
void findLen()
{
	cache[1]= port[1];
	length=1;
	for(int i=2; i<n+1; i++){
		if(cache[length] < port[i]){
			cache[++length] = port[i];
			continue;
		}
		// binary search tree and find idx
		int idx = lower_bound(cache + 1, cache + length + 1, port[i])-cache;
		cache[idx] = port[i];
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<n+1; i++)
		scanf("%d", &port[i]);
	findLen();
	printf("%d", length);
	return 0;
}
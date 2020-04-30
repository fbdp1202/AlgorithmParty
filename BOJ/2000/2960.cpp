// baekjoon 2960 yechan
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int N, K;
int cnt;
bool sieve[MAX_N+1];

int findprime(){
	for(int i=2; i<N+1; i++){
		if(!sieve[i]) return i;
	}
	return MAX_N;
}

int main()
{
	scanf("%d %d", &N, &K);
	while(1){
		int prime = findprime();
		for(int i=prime; i<N+1; i+=prime){
			if(!sieve[i]){
				sieve[i]=true;
				cnt++;
			}
			if(cnt==K){
				printf("%d", i);
				return 0;
			}
		}
	}
}
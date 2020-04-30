// baekjoon 1182 yechan
#include <iostream>
using namespace std;

int N, S, val[20];
int cnt, currentSum;

void dfs(int current){
	if(current == N) return;
	if(currentSum + val[current] == S) cnt++;

	dfs(current+1);

	currentSum += val[current];
	dfs(current+1);

	currentSum -= val[current];
}

int main(){
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	dfs(0);
	printf("%d\n", cnt);
}
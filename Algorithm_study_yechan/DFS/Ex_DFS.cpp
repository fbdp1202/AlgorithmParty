#include <cstdio>
#include <algorithm>
using namespace std;

int N, S[100000], cnt; // cnt: 사이클에 속하는 정점 개수
bool visited[100000], finished[100000];

void dfs(int curr){
	visited[curr] = true;
	int next = S[curr];
	if(visited[next]){
		if(!finished[next]){
			for(int temp=next; temp!=curr; temp=S[temp]) cnt++;
			cnt++; // 자기 자신
		}
	}
	else dfs(next);
	finished[curr] = true;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", S+i);
			S[i]--;
		}

		fill(visited, visited+N, false);
		fill(finished, visited+N, false);
		cnt = 0;
		for(int i=0; i<N; i++)
			if(!visited[i]) dfs(i);
		printf("%d\n", N-cnt);
	}
}
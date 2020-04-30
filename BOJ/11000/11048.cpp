// baekjoon 11048 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int miro[1001][1001];

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			scanf("%d", &miro[i][j]);
		}
	}

	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			miro[i][j] += max(max(miro[i-1][j-1], miro[i-1][j]), miro[i][j-1]);
		}
	}
	printf("%d", miro[N][M]);
}
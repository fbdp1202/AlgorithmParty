// baekjoon 1268 yechan
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int MAX_N=1001;

int N, board[MAX_N][6], friends[MAX_N];
bool adj[MAX_N][MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=5; j++)
			scanf("%d", &board[i][j]);

	for (int i=1; i<=5; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=j+1; k<=N; k++) {
				if (board[j][i] == board[k][i]) {
					if (!adj[j][k]) {
						adj[j][k]=adj[k][j]=true;
						friends[j]++;
						friends[k]++;
					}
				}
			}
		}
	}

	int maxV=-1;
	int maxIdx=0;
	for (int i=1; i<=N; i++) {
		if (maxV < friends[i]) {
			maxV = friends[i];
			maxIdx = i;
		}
	}
	printf("%d\n", maxIdx);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=17;

int N;
int score[MAX_N];
bool isAlive[MAX_N];
int mat[MAX_N][MAX_N];
int myNum;

int dfs(bool isday) {
	if (isday) { // day
		int maxNum = -1e9;
		int maxIdx = 0;
		for (int i=0; i<N; i++) {
			if (isAlive[i] == false) continue;
			if (maxNum < score[i]) {
				maxNum = score[i];
				maxIdx = i;
			}
		}
	    if (maxIdx == myNum) return 0;
		isAlive[maxIdx] = false;
		int ret = dfs(!isday);
		isAlive[maxIdx] = true;
		return ret;
	} else { // night
		int ret = 0;
		for (int i=0; i<N; i++) {
			if (myNum == i) continue;
			if (isAlive[i] == false) continue;
			// 아무놈 죽이기
			isAlive[i] = false;
			for (int j=0; j<N; j++) score[j] += mat[i][j];
			ret = max(ret, dfs(!isday) + 1);
			for (int j=0; j<N; j++) score[j] -= mat[i][j];
			isAlive[i] = true;
		}
		return ret;
	}
}

int main() {
	scanf("%d", &N);
	fill(isAlive, isAlive+MAX_N, true);
	for (int i=0; i<N; i++)
		scanf("%d", &score[i]);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &mat[i][j]);
	scanf("%d", &myNum);
	myNum;
	printf("%d\n", dfs(N%2!=0));
	return 0;
}
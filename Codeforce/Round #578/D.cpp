#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=2001;

int N, K;
char board[MAX_N][MAX_N];
int row[MAX_N], col[MAX_N];
int krow[MAX_N][MAX_N], kcol[MAX_N][MAX_N];
bool matRow[MAX_N], matCol[MAX_N];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=1; i<=N; i++) {
		scanf("%s", board[i]+1);
		for (int j=1; j<=N; j++) {
			if (board[i][j] == 'B') {
				row[i]++;
				col[j]++;
				krow[i][j]++;
				kcol[i][j]++;
			}
			krow[i][j] += krow[i-1][j];
			kcol[i][j] += kcol[i][j-1];
		}
	}

	int here = 0;
	for (int i=1; i<=N; i++) {
		if (row[i] == 0) {
			here++;
			matRow[i] = true;
		}
		if (col[i] == 0) {
			here++;
			matCol[i] = true;
		}
	}
	printf("here: %d\n", here);
	for (int i=1; i<=N; i++) {
		printf("%s\n", board[i]+1);
	}
	puts("");

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			printf("%d ", krow[i][j]);
		}
		puts("");
	}
	puts("");

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			printf("%d ", kcol[i][j]);
		}
		puts("");
	}
	puts("");
	puts("");

	for (int i=1; i<=N; i++) {
		printf("%d ", row[i]);
	}
	puts("");
	puts("");

	for (int i=1; i<=N; i++) {
		printf("%d ", col[i]);
	}
	puts("");
	puts("");

	int ret = 0;
	int tmp = 0;
	for (int i=K; i<=N; i++) {
		for (int j=K; j<=N; j++) {
			tmp = 0;
			for (int k=i-K+1; k<=i; k++) {
				if (matRow[k]) continue;
				if (i == 5 && j == 4) printf("%d %d %d\n", kcol[k][j], kcol[k][j-K], row[k]);
				if (kcol[k][j] - kcol[k][j-K] == row[k]){
					tmp++;
				}
			}
			for (int k=j-K+1; k<=j; k++) {
				if (matCol[k]) continue;
				if (i == 5 && j == 4) printf("%d %d %d\n", krow[i][k], krow[i-K][j], col[k]);
				if (krow[i][k] - krow[i-K][j] == col[k]) {
					tmp++;
				}
			}
			// printf("%d ", tmp);
			ret = max(ret, tmp);
		}
		// puts("");
	}
	puts("");

	printf("%d\n", ret + here);
	return 0;
}
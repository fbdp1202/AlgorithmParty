// postech Assignment5. 3.cpp
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=3001;

int t, N, M, d;
long long board[MAX_N][MAX_N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &N, &M, &d);
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=M; j++) {
				scanf("%lld", &board[i][j]);
				board[i][j] += board[i][j-1] + board[i-1][j] - board[i-1][j-1];
			}
		}

		for (int i=d; i<=N; i++) {
			for (int j=d; j<=M; j++) {
				printf("%lld ", board[i][j]-board[i-d][j]-board[i][j-d]+board[i-d][j-d]);
			}
			puts("");
		}

	}
	return 0;
}
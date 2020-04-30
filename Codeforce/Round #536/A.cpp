// CodeForce A yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 501;

int N, cnt;
char board[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", &board[i]);

	for (int i=1; i<N-1; i++) {
		for (int j=1; j<N-1; j++) {
			if (board[i][j] == 'X' &&
				board[i-1][j-1] == 'X' &&
				board[i+1][j-1] == 'X' &&
				board[i+1][j+1] == 'X' &&
				board[i-1][j+1] == 'X'){
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}
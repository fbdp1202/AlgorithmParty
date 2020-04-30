// baekjoon 15898 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, board[5][5], material[10][4][4][4];
char colors[10][4][4][4];
// [board_pos][material_pos][rotation]



int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				scanf("%d", &material[i][0][j][k]);
			}
		}
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				scanf(" %c", &colors[i][0][j][k]);
			}
		}

		// rotation fill
		for (int j=0; j<3; j++) {
			for (int k=0; k<3; k++) {
				int nj = k;
				int 
			}
		}



	}
	return 0;
}
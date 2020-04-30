// baekjoon 2580 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int done, tmp, board[9][9];
bool Checkrow[9][10];
bool Checkcol[9][10];
bool Check3x3[9][10];

inline int find_ceil(int i, int j) {
	return (i/3)*3+j/3;
}

void PrintBoard() {
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++)
			printf("%d ",board[i][j]);
		puts("");
	}
}

void BackTracking(){
	int sx=-1, sy=-1;
	for (int i=0, cnt=0; i<9; i++) {
		for (int j=0; j<9; j++, cnt++) {
			if (!board[i][j]){
				sx = i, sy = j; break;
			}
		}
		if (sx != -1) break;
	}

	if(sx == -1) {
		done=1;
		PrintBoard();
		return;
	}

	for (int num=1; num<10; num++) {
		if (!done && !Checkrow[sx][num] && !Checkcol[sy][num] && !Check3x3[find_ceil(sx, sy)][num]) {
			Checkrow[sx][num] = Checkcol[sy][num] = Check3x3[find_ceil(sx, sy)][num] = true;
			board[sx][sy] = num;
			BackTracking();
			board[sx][sy] = 0;
			Checkrow[sx][num] = Checkcol[sy][num] = Check3x3[find_ceil(sx, sy)][num] = false;
		}
	}

}

int main() {
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			scanf("%d", &tmp);
			board[i][j] = tmp;
			Checkrow[i][tmp] = true;
			Checkcol[j][tmp] = true;
			Check3x3[find_ceil(i, j)][tmp] = true;
		}
	}

	BackTracking();
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int data[MAX_N][2];
char str[MAX_N];

inline int cboard(int i, int j, int board){ return ((board>>(i*4+j)) & 1); }
inline int addboard(int i, int j, int board){ return board |= 1<<(i*4+j); }
inline int subboard(int i, int j, int board){ return board &= ~(1<<(i*4+j)); }
inline int rowCheck(int i, int board){ return 15 == (board>>(i*4) & 15); }
inline int colCheck(int j, int board){ return 4369 == (board>>(j) & 4369); }
inline int rowsub(int i, int board){ return board &= ~(15<<(i*4)); }
inline int colsub(int j, int board){ return board &= ~(4369<<(j)); }

bool checkBoard(int x, int y, char c, int board) {
	if (c == '0') {
		if (x+1 < 4 && cboard(x, y, board) == 0 && cboard(x+1, y, board) == 0)
			return true;
	} else {
		if (y+1 < 4 && cboard(x, y, board) == 0 && cboard(x, y+1, board) == 0)
			return true;
	}
	return false;
}

int fillBoard(int x, int y, char c, int board) {
	bool remove[3] = {true,};
	if (c == '0') {
		board = addboard(x, y, board);
		board = addboard(x+1, y, board);
		if (!rowCheck(x, board)) remove[0]=false;
		if (!rowCheck(x+1, board)) remove[1]=false;
		if (!colCheck(y, board)) remove[2]=false;
		if (remove[0]) board = rowsub(x, board);
		if (remove[1]) board = rowsub(x+1, board);
		if (remove[2]) board = colsub(y, board);
	} else {
		board = addboard(x, y, board);
		board = addboard(x, y+1, board);
		int i;
		if (!colCheck(y, board)) remove[0]=false;
		if (!colCheck(y+1, board)) remove[1]=false;
		if (!rowCheck(x, board)) remove[2]=false;
		if (remove[0]) board = colsub(y, board);
		if (remove[1]) board = colsub(y+1, board);
		if (remove[2]) board = rowsub(x, board);
	}
	return board;
}

bool backtracking(int depth, int board) {
	if (str[depth] == '\0') return true;
	bool rst = false;

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (cboard(i, j, board)) continue;
			if (checkBoard(i,j,str[depth], board)) {
				int newboard = fillBoard(i,j,str[depth], board);
				rst = backtracking(depth+1, newboard);
				if (rst) {
					data[depth][0] = i+1;
					data[depth][1] = j+1;
					return rst;
				}
			}
		}
	}
	return rst;
}

int main() {
	scanf("%s", &str);
	backtracking(0, 0);
	for (int i=0; str[i]; i++) {
		printf("%d %d\n", data[i][0], data[i][1]);
	}
	return 0;
}
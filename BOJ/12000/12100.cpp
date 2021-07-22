// baekjoon 12100 yechan
#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 21;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int N, board[MAX_N][MAX_N], result;
int tmpBoard[6][MAX_N][MAX_N];

int getMaxBoard(int c) {
	int ret = 0;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			ret = max(ret, tmpBoard[c][i][j]);
	return ret;
}

void moveBoard(int c) {
	if (c == 5) {
		result = max(result, getMaxBoard(c));
		return;
	}

	for (int d=0; d<4; d++) {
		for (int i=0; i<N; i++) {
			int sx = (dx[d] == 0) ? i : ((dx[d] == 1) ? 0 : N-1);
			int ex = (dx[d] == 0) ? i : ((dx[d] == 1) ? N-1 : 0);
			int sy = (dy[d] == 0) ? i : ((dy[d] == 1) ? 0 : N-1);
			int ey = (dy[d] == 0) ? i : ((dy[d] == 1) ? N-1 : 0);

			int cx = sx;
			int cy = sy;
			stack<int> st;
			while (1) {
				if (tmpBoard[c][cx][cy]) {
					st.push(tmpBoard[c][cx][cy]);
				}
				tmpBoard[c+1][cx][cy] = 0;
				if (cx == ex && cy == ey) break;
				cx += dx[d];
				cy += dy[d];
			}
			while (!st.empty()) {
				int curr_v = st.top();
				st.pop();
				if (!st.empty()) {
					int next_v = st.top();
					st.pop();
					if (curr_v == next_v) curr_v += next_v;
					else st.push(next_v);
				}
				tmpBoard[c+1][cx][cy] = curr_v;
				cx -= dx[d];
				cy -= dy[d];
			}
		}
		moveBoard(c+1);
	}
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++) {
			scanf("%d", &board[i][j]);
			tmpBoard[0][i][j] = board[i][j];
		}

	moveBoard(0);
	printf("%d\n", result);
	return 0;
}
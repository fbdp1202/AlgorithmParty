// baekjoon 2172 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=20;
const int MAX_L=11;
const int MAX_S=MAX_N*MAX_N;
const int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int N, L;
int board[MAX_N][MAX_N];
int dp[MAX_L][MAX_S][MAX_S];

inline int encode(int x, int y) { return (x*N)+y; }
inline P decode(int code) { return P(code/N, code%N); }
inline bool inRange(int x, int y) { return !(x < 0 || x >= N || y < 0 || y >= N); }
inline bool inRange(P p) { return inRange(p.first, p.second); }
inline bool inRange(int code) { return inRange(decode(code)); }
inline int getPos(P p) { return board[p.first][p.second]; }
inline int isSame(int l, int r) { return getPos(decode(l))==getPos(decode(r));}

int getNextCode(int code, int d) {
	P p = decode(code);
	if (!inRange(p.first+dir[d][0], p.second+dir[d][1])) return -1;
	return encode(p.first+dir[d][0], p.second+dir[d][1]);
}

int dfs(int num, int l, int r) {
	if (!isSame(l, r)) return 0;
	if (num == L/2) return 1;

	int &ret = dp[num][l][r];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=0; i<8; i++) {
		int ci = getNextCode(l,i);
		if (ci == -1) continue;
		for (int j=0; j<8; j++) {
			int cj = getNextCode(r, j);
			if (cj == -1) continue;
			ret += dfs(num+1, ci, cj);
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	int ret = 0;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (L % 2) {
				ret += dfs(0, encode(i, j), encode(i, j));
			} else {
				for (int d=0; d<8; d++) {
					int nx = i + dir[d][0];
					int ny = j + dir[d][1];
					if (!inRange(nx, ny)) continue;
					ret += dfs(1, encode(i,j), encode(nx,ny));
				}
			}

	printf("%d\n", ret);
	return 0;
}
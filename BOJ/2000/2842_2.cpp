// baekjoon 2842 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int MAX_N=51;
const int dx[8] = {-1,  0,  1, -1, 0, 1, -1, 1};
const int dy[8] = {-1, -1, -1,  1, 1, 1,  0, 0};

int N, totalNode, nodeCnt, height[MAX_N][MAX_N], sx, sy, ret=1e6;
int num[MAX_N*MAX_N];
vector<int> src;

char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void dfs(int x, int y, int bottom, int top) {
	for (int d=0; d<8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (!visited[nx][ny] && bottom <= height[nx][ny] && height[nx][ny] <= top) {
			if (board[nx][ny] == 'K') nodeCnt--;
			visited[nx][ny]=true;
			dfs(nx, ny, bottom, top);
		}
	}
}

bool indfs(int bottom, int top) {
	if (height[sx][sy] < bottom || top < height[sx][sy]) return false;
	memset(visited, 0, sizeof(visited));
	nodeCnt=totalNode;
	visited[sx][sy]=true;
	dfs(sx, sy, bottom, top);
	return nodeCnt==0;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf(" %s", board[i]);
		for (int j=0; j<N; j++) {
			if (board[i][j] == 'P') sx = i, sy = j;
			if (board[i][j] == 'K') totalNode++;
		}
	}

	int k=0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf(" %d", &height[i][j]);
			num[k++]=height[i][j];
		}
	}

	sort(num, num+N*N);
	int pv=0;
	for (int i=0; i<N*N; i++) {
		if (pv != num[i]) src.push_back(num[i]);
		pv = num[i];
	}

	int s = 0, e = 0;
	int ch = 0;
	int sSize = src.size();
	while (ch == 0 && s <= e && e < sSize) {
		if (indfs(src[s], src[e])) {
			int ss = s, ee = e;
			while (ss <= ee) {
				int mid = (ss+ee)/2;
				if (indfs(src[mid], src[e])) s = mid, ss = mid+1;
				else ee = mid-1;
			}
		} else {
			int ss = s + 1, ee = sSize - 1;
			ch = 1;
			while (ss <= ee) {
				int mid = (ss+ee)/2;
				if (indfs(src[s], src[mid])) ch = 0, e = mid, ee = mid - 1;
				else ss = mid + 1;
			}
		}
		if (ch == 0) ret = min(ret, src[e] - src[s]);
		s++;
	}
	printf("%d\n", ret);
	return 0;
}
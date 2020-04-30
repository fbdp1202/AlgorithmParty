// baekjoon 2819 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=100003;
const int MAX_INF=1e9;
const int MAX_M=500001;
const int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1, 0}};

int N, M;
int xpos[MAX_N], ypos[MAX_N];
ll xsum[MAX_N], ysum[MAX_N];
char cmd[MAX_M];

int cur_x, cur_y;

int getDirect(char c) {
	if (c == 'S') return 0;
	if (c == 'Z') return 1;
	if (c == 'J') return 2;
	if (c == 'I') return 3;
}

void move(char c) {
	int d = getDirect(c);
	cur_x += dir[d][0];
	cur_y += dir[d][1];
}

ll getRegion(int *pos, ll *sum, int cur) {
	int idx = lower_bound(pos, pos+N+2, cur) - pos;
	int lnum = max(0, idx-1);
	int rnum = N-lnum;
	return (1LL*lnum*cur - sum[lnum])+(sum[N] - sum[lnum] - 1LL*rnum*cur);
}

ll run() {
	return getRegion(xpos, xsum, cur_x) + getRegion(ypos, ysum, cur_y);
}

int main() {
	scanf("%d%d", &N, &M);

	xpos[0]=ypos[0]=-MAX_INF;
	xpos[N+1]=ypos[N+1]=MAX_INF;

	for (int i=1; i<=N; i++) {
		scanf("%d%d", &xpos[i], &ypos[i]);
	}

	sort(xpos, xpos+N+2);
	sort(ypos, ypos+N+2);

	for (int i=1; i<=N; i++) {
		xsum[i] = xsum[i-1] + xpos[i];
		ysum[i] = ysum[i-1] + ypos[i];
	}

	scanf("%s", cmd);
	for (int i=0; i<M; i++) {
		move(cmd[i]);
		printf("%lld\n", run());
	}

	return 0;
}
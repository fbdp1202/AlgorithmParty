// baekjoon 13567 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};

int M, N;
int value, X, Y, d;
char cmd[5];

bool checkRange(int x, int y, int m) {
	return (x < 0 || x >= m || y < 0 || y >= m);
}

int main() {
	scanf("%d %d", &M, &N);

	for (int i=0; i<N; i++) {
		scanf(" %s %d", cmd, &value);
		if (cmd[0] == 'M') {
			X += dx[d]*value; Y += dy[d]*value;
			if (checkRange(X,Y,M)) return !printf("-1\n");
		} else {
			if (value) d = (d+1)%4;
			else d = (d+3)%4;
		}
	}
	printf("%d %d\n", X, Y);
	return 0;
}
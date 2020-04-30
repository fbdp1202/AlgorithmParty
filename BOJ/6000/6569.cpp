// baekjoon 6569 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_H=12;
const int SIZE=(1<<MAX_H);

int H, W;
int dp[MAX_H][SIZE];
bool pattern[MAX_H][SIZE];

void dfs(int pos, int w, int here) {
	if (pos > w) return;
	if ((w-pos+1) & 1) pattern[w][here]=true;
	if (pos == w) return;
	dfs(pos+2, w, here);
	dfs(pos+1, w, here | (1<<(pos))); // mask 1
}

int main()
{
	for (int w=1; w<MAX_H; w++) {
		dfs(pos, w, 0);
	}

	while (1) {
		scanf("%d%d", &H, &W);

	}
	return 0;
}
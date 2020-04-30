// baekjoon 9177 yechan
#include <cstdio>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_W 222

int T;
char word1[MAX_W], word2[MAX_W], mixword[MAX_W*2];
int visited[MAX_W][MAX_W];
int lw1, lw2;

bool backtracking(int w1, int w2, int midx) {
	if (lw1 == w1 && lw2 == w2) return 1;
	if (visited[w1][w2] != -1) return visited[w1][w2];
	visited[w1][w2] = 0;
	if (word1[w1] == mixword[midx]) visited[w1][w2] = backtracking(w1+1, w2, midx+1);
	if (visited[w1][w2]) return 1;
	if (word2[w2] == mixword[midx]) visited[w1][w2] = backtracking(w1, w2+1, midx+1);
	return visited[w1][w2];
}

int main() {
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		memset(visited, -1, sizeof(visited));
		scanf("%s %s %s", word1, word2, mixword);
		lw1 = strlen(word1), lw2 = strlen(word2);
		printf("Data set %d: ", i);
		puts(backtracking(0,0,0) ? "yes" : "no");
	}
	return 0;
}
// baekjoon 10801 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int board[10], score[2];

int main() {
	for (int i=0; i<10; i++)
		scanf("%d", &board[i]);
	for (int i=0; i<10; i++) {
		int x;
		scanf("%d", &x);
		if (board[i] > x) score[0]++;
		if (board[i] < x) score[1]++;
	}
	if (score[0] == score[1]) printf("D\n");
	if (score[0] > score[1]) printf("A\n");
	if (score[1] > score[0]) printf("B\n");
	return 0;
}
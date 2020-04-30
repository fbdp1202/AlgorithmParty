// baekjoon 1652 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100
char room[MAX_N][MAX_N];
int N, pb, db, num;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf(" %c", &room[i][j]);
	for (int i=0; i<N; i++) {
		pb=0, db=0;
		for (int j=0; j<N; j++) {
			if (room[i][j]=='X') pb=0, db=0;
			else {
				if (pb && !db) num++, db=1;
				pb=1;
			}
		}
	}
	printf("%d ", num);
	num=0;
	for (int i=0; i<N; i++) {
		pb=0, db=0;
		for(int j=0; j<N; j++) {
			if (room[j][i]=='X') pb=0, db=0;
			else {
				if (pb && !db) num++, db=1;
				pb=1;
			}
		}
	}
	printf("%d", num);
	return 0;
}
// baekjoon 2530 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A,B,C,D;
int main() {
	scanf("%d%d%d%d", &A, &B, &C, &D);
	int result = (((A*60+B)*60+C) + D)%(24*60*60);
	printf("%d %d %d\n", result/3600, (result%3600)/60, result%60);
	return 0;
}
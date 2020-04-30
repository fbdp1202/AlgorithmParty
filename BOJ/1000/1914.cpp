// baekjoon 1914 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 101
typedef double ll;

int N, flag; 
char data[35];
ll cnt;
ll numCnt[MAX_N];

ll hanoi(int start, int other, int dest, int n) {
	if (numCnt[n]) return numCnt[n];
	if (n == 1) return 1;
	ll rst = 0;
	rst += hanoi(start, dest, other, n-1);
	rst += hanoi(start, other, dest, 1);
	rst += hanoi(other, start, dest, n-1);
	return numCnt[n] = rst;
}

void Printhanoi(int start, int other, int dest, int n) {
	if (n == 1) {
		printf("%d %d\n", start, dest);
	} else {
		Printhanoi(start, dest, other, n-1);
		Printhanoi(start, other, dest, 1);
		Printhanoi(other, start, dest, n-1);
	}
}

void postprocessing() {
	int i = 0;
	while (data[++i]);
	data[i-1] = data[i-1]-1;
}

int main() {
	scanf("%d", &N);
	cnt = pow(2,N);
	sprintf(data, "%.0f", cnt);
	postprocessing();
	printf("%s\n", data);
	if (N <= 20) {
		flag = 1;
		Printhanoi(1,2,3,N);
	}
	return 0;
}
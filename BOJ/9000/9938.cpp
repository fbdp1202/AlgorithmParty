// baekjoon 9938 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 300000

int n, m, p[MAX_N+1], beer[MAX_N+1];

int find(int n) {
	if(p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(beer[a] && beer[b]) return false;
	if(beer[b]) 		beer[a] = 1;
	else if(beer[a]) 	beer[b] = 1;
	else 				beer[a] = 1;
	if(a == b) return true;
	p[a] = b;
	return true;
}

int main() {
	scanf("%d %d", &m, &n);
	int a, b;
	fill(p, p+MAX_N, -1);
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if(merge(a, b)) printf("LADICA\n");
		else 			printf("SMECE\n");
	}
	return 0;
}
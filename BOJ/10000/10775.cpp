// baekjoon 10775 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_G 100000
int G, P, rst, tmp, gate[MAX_G+1];

int find(int n) {
	if(gate[n] < 0) return n;
	gate[n] = find(gate[n]);
	return gate[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	gate[a] = b;
}

bool findGate(int a) {
	a = find(a);
	if(a > 0) 	merge(a, a-1);
	else 		return false;
	return true;
}

int main() {
	scanf("%d %d", &G, &P);
	fill(gate, gate+MAX_G+1, -1);
	for(int i=0; i<P; i++) {
		scanf("%d", &tmp);
		if(findGate(tmp)) 	rst++;
		else 				break;
	}
	printf("%d", rst);
}
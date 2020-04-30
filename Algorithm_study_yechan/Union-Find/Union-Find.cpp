#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1000;
int p[MAX_N+1];

int find(int n){
	if(p[n] < 0) return n;
	return find(p[n]);
}

int find(int n){
	if(p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[b] = a;
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[a] += p[b];
	p[b] = a;
}

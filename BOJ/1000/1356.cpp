// baekjoon 1356 yechna
#include <bits/stdc++.h>
using namespace std;

int N, arr[20];

int main() {
	scanf("%d", &N);
	int pos = 0;
	while (N) {
		arr[pos++] = N%10;
		N/=10;
	}
	// div position
	bool isPossible = false;
	for (int div=1; div<pos; div++) {
		int A=1, B=1;
		for (int i=0; i<div; i++) A *= arr[i];
		for (int i=div; i<pos; i++) B *= arr[i];
		if (A == B) isPossible = true;
	}
	puts(isPossible ? "YES" : "NO");
	return 0;
}
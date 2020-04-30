// baekjoon 2869 yechan
#include <bits/stdc++.h>
using namespace std;

int A, B, V;

int main() {
	scanf("%d%d%d", &A, &B, &V);
	printf("%d\n", 1+(max(0,V-B-1))/(A-B));
	return 0;
}
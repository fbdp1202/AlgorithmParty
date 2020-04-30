// baekjoon 2864 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 8
char A[MAX_N], B[MAX_N];
int maxA, minA, maxB, minB;

int main() {
	scanf("%s %s", A, B);
	int la = strlen(A);
	int lb = strlen(B);
	for (int i=0; i<la; i++) {
		maxA*=10; minA*=10;
		if(A[i]=='5'||A[i]=='6') maxA +=6, minA +=5;
		else maxA += A[i]-'0', minA += A[i] - '0';
	}
	for (int i=0; i<lb; i++) {
		maxB*=10; minB*=10;
		if(B[i]=='5'||B[i]=='6') maxB +=6, minB +=5;
		else maxB += B[i]-'0', minB += B[i] - '0';
	}
	printf("%d %d", minA+minB, maxA+maxB);
	return 0;
}
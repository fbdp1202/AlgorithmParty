// baekjoon 13484 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int X, N, P, result;

 int main() {
 	scanf("%d", &X);
 	scanf("%d", &N);
 	result = N*X+X;
 	for (int i=0; i<N; i++){
 		scanf("%d", &P);
 		result -= P;
 	}
 	printf("%d", result);
 	return 0;
 }
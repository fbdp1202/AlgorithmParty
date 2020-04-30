// baekjoon 11576 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A, B;
int m, N;
int data[26];
int ret[100];

int main() {
	scanf("%d %d", &A, &B);
	scanf("%d", &m);
	for (int i=0; i<m; i++)
		scanf("%d", &data[i]);
	for (int i=0; i<m; i++) {
		N*=A;
		N+=data[i];
	}
	int slen=0;
	while (N) {
		ret[slen++] = N%B;
		N/=B;
	}
	for (int i=slen-1; i>=0; i--)
		printf("%d ", ret[i]);
	puts("");
	return 0;
}
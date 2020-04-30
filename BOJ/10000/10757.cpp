// baekjoon 10757 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=11111;

char A[MAX_N], B[MAX_N];
int data[MAX_N];

int main() {
	scanf("%s%s", A, B);
	int alen = strlen(A);
	int blen = strlen(B);

	int sum = 0;
	int pos = 0;
	for (int i=1; i<MAX_N; i++) {
		if (!sum && i > alen && i > blen) {
			pos = i-1; break;
		}
		if (alen-i >= 0) sum += (A[alen-i] - '0');
		if (blen-i >= 0) sum += (B[blen-i] - '0');
		data[i] = sum % 10;
		sum /= 10;
	}
	for (int i=pos; i>0; i--)
		printf("%d", data[i]);
	puts("");

	return 0;
}
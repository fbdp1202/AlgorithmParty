// baekjoon 9243 yechan
#include <bits/stdc++.h>
using namespace std;

int N;
char A[1111];
char B[1111];

bool check() {
	int C = N%2;
	for (int i=0; A[i]; i++)
		if (((A[i]-'0')^(B[i]-'0'))^C)
			return false;
	return true;
}

int main() {
	scanf("%d", &N);
	scanf("%s%s", A, B);
	puts(check() ? "Deletion succeeded":"Deletion failed");
	return 0;
}
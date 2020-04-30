// baekjoon 4999 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[1001], B[1001];

int main()
{
	scanf("%s%s", A, B);
	puts(strlen(A) < strlen(B) ? "no":"go");
	return 0;
}
// baekjoon 12813 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=100001;

char A[MAX_N], B[MAX_N];

int main()
{
	scanf("%s%s", A, B);

	for (int i=0; i<100000; i++)
		printf("%d", (A[i]-'0') & (B[i]-'0'));
	puts("");
	for (int i=0; i<100000; i++)
		printf("%d", (A[i]-'0') | (B[i]-'0'));
	puts("");
	for (int i=0; i<100000; i++)
		printf("%d", (A[i]-'0') ^ (B[i]-'0'));
	puts("");
	for (int i=0; i<100000; i++)
		printf("%d", !(A[i]-'0'));
	puts("");
	for (int i=0; i<100000; i++)
		printf("%d", !(B[i]-'0'));
	puts("");

	return 0;
}
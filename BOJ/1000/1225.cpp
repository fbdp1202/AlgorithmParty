// baekjoon 1225 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=10001;

char A[MAX_N], B[MAX_N];

int main()
{
	scanf("%s%s", A, B);

	long long ret = 0;
	for (int i=0; A[i]; i++) {
		for (int j=0; B[j]; j++) {
			ret += (A[i]-'0')*(B[j]-'0');
		}
	}
	printf("%lld\n", ret);
	return 0;
}
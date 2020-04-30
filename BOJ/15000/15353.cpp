// baekjoon 15353 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX_N=10002;

char A[MAX_N], B[MAX_N];

int main()
{
	scanf("%s%s", A, B);
	int Alen = strlen(A);
	int Blen = strlen(B);

	int length = max(Alen, Blen);
	stack<int> st;
	int nx = 0;
	for (int i=1; i<=length; i++) {
		if (i <= Alen) nx += (A[Alen-i] - '0');
		if (i <= Blen) nx += (B[Blen-i] - '0');
		st.push(nx%10);
		nx /= 10;
	}
	if (nx != 0) st.push(nx);

	if (st.empty()) printf("0\n");
	else {
		while (!st.empty()) {
			printf("%d", st.top());
			st.pop();
		}
		puts("");
	}

	return 0;
}
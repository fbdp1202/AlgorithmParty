#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_N=300001;

int N;
char S[MAX_N];
int count[MAX_N];

int error() {
	printf(":(\n");
	return 0;
}

int main() {
	scanf("%d", &N);
	scanf("%s", S);
	if (N % 2) return error();
	int open=0, close=0;
	for (int i=0; S[i]; i++) {
		if (S[i] == '(') open++;
	}
	close=N/2-open;
	for (int i=0; S[i]; i++) {
		if (S[i] == '?') {
			if (close-- > 0) S[i] = '(';
			else S[i] = ')';
		}
	}
	open = close = 0;
	for (int i=0; S[i]; i++) {
		if (S[i] == '(') open++;
		else open--;
		if (open < 0) return error();
		if (!open) close++;
	}
	if (open) return error();
	if (close != 1) return error();
	printf("%s\n", S);

	return 0;
}
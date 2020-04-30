// baekjoon 16503 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, ret0, ret1;
char op1, op2;

inline int compute(int a, int b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int main() {
	scanf("%d %c %d %c %d", &a, &op1, &b, &op2, &c);
	ret0 = compute(compute(a, b, op1), c, op2);
	ret1 = compute(a, compute(b, c, op2), op1);
	if (ret1 < ret0) swap(ret0, ret1);
	printf("%d\n%d\n", ret0, ret1);
	return 0;
}
// baekjoon 1357 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int A, B;

int rev(int n) {
	int tmp=0;
	while (n) {
		tmp *= 10;
		tmp += n%10;
		n /= 10;
	}
	return tmp;
}

int main() {
	scanf("%d %d", &A, &B);
	printf("%d", rev(rev(A)+rev(B)));
	return 0;
}
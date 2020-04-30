// baekjoon 8230 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, result;

int getNum(int a) {
	int cnt = 0;
	for (int i=1; i*i<=a; i++)
		if (a%i == 0)
			cnt++;

	return cnt;
}

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		result += getNum(i);
	}
	printf("%d\n", result);
	return 0;
}
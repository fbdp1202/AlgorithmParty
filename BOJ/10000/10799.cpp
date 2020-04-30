// baekjoon 10799 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char c;
int depth, result, pv;

int main() {
	while (scanf(" %c", &c) != -1) {
		if (c == '(') {
			depth++;
			pv = 1;
		}
		else {
			depth--;
			if (pv)
				result += depth;
			else 
				result++;
			pv = 0;
		}
	}
	printf("%d\n", result);
	return 0;
}
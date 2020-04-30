// baekjoon 1731 yechan
#include <cstdio>
using namespace std;

int main() {
	int n, prev, curr, step, on;
	scanf("%d", &n);
	scanf("%d", &prev);
	scanf("%d", &curr);
	step = curr-prev;
	prev = curr;
	scanf("%d", &curr);
	if (step == curr-prev) {
		on = 0;
	} else {
		on = curr/prev;
	}
	for (int i=3; i<n; i++) {
		scanf("%d", &curr);
	}
	if (on) {
		curr *= on;
	}else {
		curr += step;
	}
	printf("%d", curr);
	return 0;
}
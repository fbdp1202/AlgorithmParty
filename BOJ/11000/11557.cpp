// baekjoon 11557 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_S=21;

int T, N, maxV=-1, value;
char data[21], ret[21];

void change() {
	maxV = value;
	for (int i=0; i<21; i++) ret[i] = data[i];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%s %d", data, &value);
			if (value > maxV) change();
		}
		puts(ret);
	}
	return 0;
}
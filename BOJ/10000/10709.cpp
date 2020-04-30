// baekjoon 10709 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char data[101];

int H, W;
int main() {
	scanf("%d%d", &H, &W);
	for (int i=0; i<H; i++) {
		scanf("%s", data);
		int pos = -1;
		for (int j=0; j<W; j++) {
			if (pos != -1) pos++;
			if (data[j] == 'c') pos=0;
			printf("%d ", pos);
		}
		puts("");
	}
	return 0;
}
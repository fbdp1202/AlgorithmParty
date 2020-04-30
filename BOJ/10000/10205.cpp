// baekjoon 10205 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, H;
char str[101];

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Data Set %d:\n", t);
		scanf("%d", &H);
		scanf("%s", str);
		for (int i=0; str[i]; i++) {
			if (str[i] == 'b') H--;
			else H++;
		}
		printf("%d\n\n", H);
	}
	return 0;
}
// baekjoon 10258 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N=33;
int T;
char str[MAX_N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);

		int i = 0;
		while (str[i] == '0') {
			i++;
		}
		if (str[i] == '\0') {
			printf("0\n");
			continue;
		}
		i++;

		ll ret = 2;
		int match = 1;
		for (; str[i]; i++) {
			ret *= 2;
			if (str[i]-'0' == match) ret--;
			if (str[i] == '1') match^=1;
		}
		printf("%d\n", ret-1);
	}
	return 0;
}
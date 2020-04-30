// baekjoon 11024 yechan
#include <bits/stdc++.h>
using namespace std;

int T;
char str[777];

int main() {
	scanf("%d", &T);
	getchar();
	while (T--) {
		int ret = 0;
		fgets(str, 777, stdin);
		for (int i=0; str[i]; i++) {
			int tmp = 0;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
				tmp *=10;
				tmp += str[i]-'0';
				i++;
			}
			ret += tmp;
			if (str[i] == '\0') break;
		}
		printf("%d\n", ret);
	}
	return 0;
}
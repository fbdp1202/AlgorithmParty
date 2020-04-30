// baekjoon 6321 yechan
#include <bits/stdc++.h>
using namespace std;

int T;
char str[55];

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("String #%d\n",t);
		scanf("%s", &str);
		for (int i=0; str[i]; i++)
			printf("%c", (str[i]-'A'+1)%26+'A');
		puts("\n");
	}
	return 0;
}
// baekjoon 4458 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[33];

int main(){
	int N;
	scanf("%d", &N);
	fgets(str, 33, stdin);
	while (N--) {
		fgets(str, 33, stdin);
		if ('a' <= str[0] && str[0] <= 'z') str[0] = (str[0] - 'a') + 'A';
		printf("%s", str);
	}
	return 0;
}
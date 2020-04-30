// baekjoon 10926 yechan
#include <cstdio>
using namespace std;

char buf[53];

int main() {
	int i=0;
	scanf("%s", buf);
	while (buf[i]){
		i++;
	}
	buf[i++] = '?';
	buf[i++] = '?';
	buf[i++] = '!';
	buf[i++] = '\0';
	printf("%s", buf);
	return 0;
}
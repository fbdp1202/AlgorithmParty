// baekjoon 2743 yechan
#include <cstdio>

char buf[101];

int main() {
	int i=0;
	scanf("%s", &buf);
	while(buf[i]){
		i++;
	}
	printf("%d",i);
	return 0;
}
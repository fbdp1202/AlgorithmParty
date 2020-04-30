// baekjoon 10952 yechan
#include <cstdio>

int main() {
	int A, B;
	while (1){
		scanf("%d%d",&A,&B);
		if(!A && !B) break;
		printf("%d\n",A+B);
	}
	return 0;
}
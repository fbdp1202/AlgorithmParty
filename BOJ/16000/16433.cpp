// baekjoon 16433 yechan
#include <cstdio>

int main() {
	int N, R, C;
	scanf("%d%d%d",&N,&R,&C);
	int flag = (R+C)%2;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if ( (i+j)%2 == flag )
				printf("v");
			else 
				printf(".");
		}
		puts("");
	}
	return 0;
}
// baekjoon 5063 yechan
#include <cstdio>
int main()
{
	int T;
	int r,e,c;
	scanf("%d", &T);
	for(int i=0; i<T; i++)
	{
		scanf("%d %d %d", &r, &e, &c);
		if(r > e-c) 		printf("do not advertise\n");
		else if(r == e-c) 	printf("does not matter\n");
		else 				printf("advertise\n");
	}
}
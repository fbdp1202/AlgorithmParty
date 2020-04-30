// baekjoon 2884 yechan
#include <cstdio>
using namespace std;

int main()
{
	int M,N;
	scanf("%d %d", &M, &N);
	int Total=(24*60+M*60+N-45)%(24*60);
	printf("%d %d", Total/60, Total%60);
}
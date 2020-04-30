// baekjoon 3003 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int match[6]={1,1,2,2,2,8};

int main()
{
	int x;
	for (int i=0; i<6; i++) {
		scanf("%d", &x);
		printf("%d ", match[i]-x);
	}
	puts("");
	return 0;
}
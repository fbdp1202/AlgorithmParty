// baekjoon 5554 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int result, tmp;

int main() {
	for (int i=0; i<4; i++)
		scanf("%d",&tmp), result+=tmp;
	printf("%d\n%d",result/60, result%60);
	return 0;
}
// baekjoon 1309 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100001
#define DIV_NUM 9901
int n, zeorL, upL, downL;
int tmpz, tmpu, tmpd;

int main()
{
	scanf("%d", &n);
	zeorL = 1;
	upL = 1;
	downL = 1;

	for(int i=1; i<n; i++){
		tmpz = zeorL;  tmpu = upL;	tmpd = downL;
		zeorL = (tmpu + tmpd + tmpz)%DIV_NUM;
		upL = (tmpd + tmpz)%DIV_NUM;
		downL = (tmpu + tmpz)%DIV_NUM;
	}
	printf("%d", (zeorL+upL+downL)%DIV_NUM);
	return 0;
}
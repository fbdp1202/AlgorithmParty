// baekjoon 1427 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int num[10];

int main()
{
	char ch;
	while( (ch=getchar()) && ch != EOF && ch != '\n')
		num[ch-'0']++;

	for(int i=9; i>=0; i--)
		for(int j=0; j<num[i]; j++)
			printf("%d",i);

	return 0;
}
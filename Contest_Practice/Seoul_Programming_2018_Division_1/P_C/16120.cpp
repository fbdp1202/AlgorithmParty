// baekjoon 6603 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_LEN 1000001

char buf[MAX_LEN];

int main()
{
	scanf("%s", buf);

	int len = strlen(buf);

	int num_P = 0;
	int num_A = 0;
	for(int i = 0; i < len; i++)
	{
		if(buf[i] == 'P') num_P++;
		if(buf[i] == 'A') num_A++;
		if( (num_P == 1 && num_A == 1) || (num_A > 1) ) break;
		if(num_P >= 3 && num_A == 1 && buf[i-1] == 'A' && buf[i] == 'P')
		{
			num_P -= 2;
			num_A -= 1;
		}
	}
	if(num_P == 1 && num_A == 0) 	printf("PPAP\n");
	else 			printf("NP");
}
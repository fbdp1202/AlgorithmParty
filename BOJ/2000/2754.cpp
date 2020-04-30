// baekjoon 2754 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	char str[3];
	scanf("%s", str);
	float ret = 0;
	if (str[0] == 'A') ret += 4.0;
	if (str[0] == 'B') ret += 3.0;
	if (str[0] == 'C') ret += 2.0;
	if (str[0] == 'D') ret += 1.0;

	if (str[1] == '+') ret += 0.3;
	if (str[1] == '-') ret += -0.3;
	printf("%.1f\n", ret);
	return 0;
}
// baekjoon 1769 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000001;
char data[MAX_N];

int main()
{
	scanf("%s", data);
	int ret = 0;
	if (!data[1]) return !printf("0\n%s\n", ((data[0]-'0')%3 == 0) ? "YES" : "NO");

	int cnt = 1;
	for (int i=0; data[i]; i++)
		ret += data[i] - '0';

	int tmp;
	while (ret >= 10) {
		tmp = ret;
		ret = 0;
		while (tmp) {
			ret += tmp % 10;
			tmp /= 10;
		}
		cnt++;
	}
	printf("%d\n%s\n", cnt, ret % 3 == 0 ? "YES" : "NO");
	return 0;
}
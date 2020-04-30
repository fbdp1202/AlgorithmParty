// baekjoon 4084 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, d;
int tmp[4];

void gen()
{
	tmp[0] = abs(a-b);
	tmp[1] = abs(b-c);
	tmp[2] = abs(c-d);
	tmp[3] = abs(d-a);
	a = tmp[0];
	b = tmp[1];
	c = tmp[2];
	d = tmp[3];
}

int game()
{
	int ret = 0;
	while (1) {
		if (a == b && b == c && c == d) break;
		gen();
		ret++;
	}
	return ret;
}

int main()
{
	while (1)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a+b+c+d==0) break;
		printf("%d\n", game());
	}

	return 0;
}
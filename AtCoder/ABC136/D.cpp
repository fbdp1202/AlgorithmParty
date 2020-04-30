#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=100001;
char str[MAX_N];
int person[MAX_N];

int getLen(int here, char match, int dir)
{
	if (here < 0 || str[here] == '\0') return 0;
	if (str[here] != match) return 0;
	return 1 + getLen(here + dir, match, dir);
}

int main()
{
	scanf("%s", str);
	for (int i=1; str[i]; i++)
	{
		if (str[i-1] == 'R' && str[i] == 'L')
		{
			int left = getLen(i-1, 'R', -1);
			int right = getLen(i, 'L', 1);
			left--, right--;
			person[i-1] = (left/2 + right/2 + right%2) + 1;
			person[i] = (left/2 + right/2 + left%2) + 1;
		}
	}

	for (int i=0; str[i]; i++)
		printf("%d ", person[i]);
	puts("");
	return 0;
}
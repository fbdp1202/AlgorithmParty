// baekjoon 9584 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int ret, ans[MAX_N];
char origin[10];
char str[MAX_N][10];

bool check(int pos) 
{
	for (int i=0; i<9; i++) {
		if (origin[i] == '*') continue;
		if (origin[i] != str[pos][i]) return false;
	}
	return true;
}

int main()
{
	scanf("%s", origin);

	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", str[i]);

	for (int i=0; i<N; i++)
		if (check(i))
			ans[ret++]=i;

	printf("%d\n", ret);
	for (int i=0; i<ret; i++)
		printf("%s\n", str[ans[i]]);

	return 0;
}
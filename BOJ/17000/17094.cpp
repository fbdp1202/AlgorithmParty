// baekjoon 17094 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[100001];
int main()
{
	int N;
	scanf("%d", &N);
	scanf("%s", str);
	int ans[2]={0};
	for (int i=0; str[i]; i++) {
		if (str[i] == '2') ans[0]++;
		if (str[i] == 'e') ans[1]++;
	}
	if (ans[0] == ans[1]) puts("yee");
	else if (ans[0] > ans[1]) puts("2");
	else puts("e");
	return 0;
}
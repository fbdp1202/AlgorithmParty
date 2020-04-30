// baekjoon 3059 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=1001;
char str[MAX_N];
bool visited[26];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(visited, 0, sizeof(visited));
		scanf("%s", str);
		for (int i=0; str[i]; i++)
			visited[str[i]-'A'] = true;
		int ret = 0;
		for (int i=0; i<26; i++)
			if (!visited[i])
				ret += i+'A';
		printf("%d\n", ret);
	}
	return 0;
}
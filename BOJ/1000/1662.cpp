// baekjoon 1662 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_S=51;

int pos;
char str[MAX_S];

int dfs() {
	int count = 0;
	while (str[pos]) {
		if (str[pos] == ')') {
			pos++;
			return count;
		}

		if (str[pos] == '(') {
			count--; // do not count repeated string
			int mul = str[pos-1]-'0';
			pos++;
			count += mul*dfs();
		}
		else {
			count++;
			pos++;
		}
	}
	return count;
}

int main()
{
	scanf("%s", &str);
	printf("%d\n", dfs());
	return 0;
}
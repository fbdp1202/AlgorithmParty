// baekjoon 9093 yechan
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

char str[1001];

int main()
{
	int T;
	scanf("%d", &T);
	fgets(str, 1000, stdin);
	while (T--)
	{
		fgets(str, 1000, stdin);
		stack<char> s;
		for (int i=0; str[i]; i++) {
			if (str[i] == ' ' || str[i] == '\n') {
				while (!s.empty()) {
					printf("%c", s.top());
					s.pop();
				}
				printf("%c", str[i]);
			} else {
				s.push(str[i]);
			}
		}
		while (!s.empty()) {
			printf("%c", s.top());
			s.pop();
		}
	}
	return 0;
}
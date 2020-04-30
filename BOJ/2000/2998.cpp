// baekjoon 2998 yechan
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

char str[101];
stack<int> st;

int main() {
	scanf("%s", str);
	int slen = (int)strlen(str);
	int num = 0;
	for (int i=slen-1, p=0; i>=0; i--, p++) {
		if (p == 3) {
			st.push(num);
			p=0;
			num=0;
		}
		num += (str[i]-'0')<<p;
	}
	st.push(num);
	while (!st.empty()) {
		printf("%d", st.top());
		st.pop();
	}
	printf("\n");
	return 0;
}
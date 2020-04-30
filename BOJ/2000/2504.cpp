// baekjoon 2504 reference
#include <cstdio>
#include <stack>
using namespace std;

int sum, tmp = 1;
char str[33];
stack<char> st;

int main() {
	scanf("%s", str+1);

	for (int i = 1; str[i]; i++) {
		switch (str[i]) {
			case '(':
				tmp *= 2, st.push('('); break;
			case '[':
				tmp *= 3, st.push('['); break;
			case ')':
				if (str[i - 1] == '(') sum += tmp;
				if (st.empty()) return !printf("0");
				if (st.top() == '(') st.pop();
				tmp /= 2; break;
			case ']':
				if (str[i - 1] == '[') sum += tmp;
				if (st.empty()) return !printf("0");
				if (st.top() == '[') st.pop();
				tmp /= 3; break;
		}
	}
	printf("%d", st.empty() ? sum : 0);

	return 0;
}
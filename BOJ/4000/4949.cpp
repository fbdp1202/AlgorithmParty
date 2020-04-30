// baekjoon 4949 yechan
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_N=111;

char S[MAX_N];

int main() {
	while (1) {
		scanf("%100[^\n]s", S);
		getchar();
		if (S[0] == '.' && strlen(S) == 1) break;
		stack<char> st;
		bool flag = true;
		for (int i=0; S[i]; i++) {
			if (S[i] == '(' || S[i] == '[') {
				st.push(S[i]);
			}
			if (S[i] == ')') {
				if (st.empty() || st.top() != '(') {
					flag=false;
					break;
				}
				st.pop();
			}
			if (S[i] == ']') {
				if (st.empty() || st.top() != '[') {
					flag=false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty()) flag=false;
		printf("%s\n", flag ? "yes" : "no");
	}
	return 0;
}
// baekjoon 1935 yechan
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int N;
double alpha[26];
char str[101];

int main() {
	scanf("%d", &N);
	scanf("%s", str);
	for (int i=0; i<N; i++)
		scanf("%lf", &alpha[i]);

	stack<double> st;
	for (int i=0; str[i]; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') st.push(alpha[str[i]-'A']);
		else {
			double a, b, c;
			b = st.top(); st.pop();
			a = st.top(); st.pop();
			switch(str[i]) {
				case '+': c = a + b; break;
				case '-': c = a - b; break;
				case '*': c = a*b; break;
				case '/': c = a/b; break;
			}
			st.push(c);
		}
	}
	printf("%.2lf\n", st.top());
	return 0;
}
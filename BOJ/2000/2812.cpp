// baekjoon 2812 yechan
#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
const int MAX_N=500001;

P data[MAX_N];
char str[MAX_N];
bool visited[MAX_N];

int N, K;
stack<P> st;

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", str);

	for (int i=0; str[i]; i++) {
		while (K > 0 && !st.empty() && st.top().first < (str[i]-'0')) {
			visited[st.top().second] = true;
			st.pop();
			K--;
		}
		if (!K) break;
		st.push(P(str[i]-'0', i));
	}
	while (K > 0) {
		visited[st.top().second] = true;
		K--;
		st.pop();
	}

	for (int i=0; i<N; i++)
		if (!visited[i])
			printf("%c", str[i]);
	puts("");
	return 0;
}
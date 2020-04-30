// baekjoon 17298 yechan
#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

const int MAX_N=1000001;
const int MAX_INF=2e9;

int N, data[MAX_N];
int ans[MAX_N];
stack<P> st;

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);

	for (int i=0; i<N; i++) {
		while (!st.empty() && st.top().second < data[i]) {
			ans[st.top().first] = data[i];
			st.pop();
		}
		st.push(P(i, data[i]));
	}
	while (!st.empty()) {
		ans[st.top().first] = -1;
		st.pop();
	}
	for (int i=0; i<N; i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
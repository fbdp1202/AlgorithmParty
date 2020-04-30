// baekjoon 10773 yechan
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

int K, x;
stack<int> st;
ll sum;

int main() {
	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		scanf("%d", &x);
		if (x) {
			sum += x;
			st.push(x);
		} else {
			sum -= st.top();
			st.pop();
		}
	}
	printf("%lld\n", sum);
	return 0;
}
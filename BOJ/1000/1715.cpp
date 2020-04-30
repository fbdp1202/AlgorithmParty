// baekjoon 1715 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;

int N;
ll result;

int main(){
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		PQ.push(x);
	}
	N--;
	while (N--) {
		ll tmp = PQ.top(); PQ.pop();
		tmp += PQ.top(); PQ.pop();
		PQ.push(tmp);
		result += tmp;
	} 
	printf("%lld\n", result);
	return 0;
}
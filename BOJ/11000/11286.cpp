// baekjoon 11286 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
typedef pair<int,int> P;
int N, x;

int main() {
	priority_queue<P, vector<P>, greater<P>> PQ;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &x);
		if (x == 0) {
			if (PQ.empty()) {
				puts("0");
			} else {
				x = PQ.top().first * PQ.top().second;
				PQ.pop();
				printf("%d\n", x);
			}
		} else if (x > 0){
			PQ.push({x,1});
		} else {
			PQ.push({-x,-1});
		}
	}
	return 0;
}
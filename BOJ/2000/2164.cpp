// baekjoon 2164 yechan
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N, ret;
queue<int> q;

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		q.push(i);

	bool flag=true;
	while (!q.empty()) {
		ret = q.front();
		if (flag) {
			flag = false;
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
			flag=true;
		}
	}
	printf("%d\n", ret);
	return 0;
}
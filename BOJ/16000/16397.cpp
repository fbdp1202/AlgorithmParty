// baekjoon 16397 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, T, G;
bool visited[100001];

int main() {
	scanf("%d %d %d", &N, &T, &G);

	queue<int> q;

	q.push(N);
	visited[N]=true;

	int depth = 0, tmp = 0;
	while (q.size()) {
		int qSize = q.size();
		while (qSize--) {
			tmp = q.front();
			q.pop();
			if (tmp == G) {
				break;
			}
			if ((tmp + 1) < 100000) {
				if (!visited[tmp+1]){
					q.push(tmp+1);
					visited[tmp+1]=true;
				}
			}
			if (tmp) {
				if (tmp*2 < 100000) {
					int count = 1;
					int tmp1 = 2*tmp;
					while (tmp1/10) {
						tmp1/=10;
						count*=10;
					}
					if(!visited[2*tmp-count]) {
						visited[2*tmp-count] = true;
						q.push(2*tmp-count);
					}
				}
			} else {
				if (!visited[tmp]){
					q.push(tmp);
					visited[tmp] = true;
				}
			}
		}
		if(tmp == G) {
			break;
		}
		depth++;
		if(depth > T) break;
	}
	if (tmp == G) printf("%d\n", depth);
	else printf("ANG\n");
	return 0;
}
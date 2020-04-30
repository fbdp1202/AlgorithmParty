// baekjoon 2457 yechan
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
int m[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int N, s=59, e=333;
pair<int, int> flowers[MAX_N];

int convNum(int month, int day) {
	int ret=0;
	for (int i=0; i<month-1; i++) ret +=m[i];
	return ret+day-1;
}

int no() {
	printf("0\n");
	return 0;
}
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int m1,d1,m2,d2;
		scanf("%d%d%d%d", &m1, &d1, &m2, &d2);
		flowers[i].first = convNum(m1, d1);
		flowers[i].second = convNum(m2, d2)-1;
	}
	sort(flowers, flowers+N);
	priority_queue<int> q;
	int cur_s=s-1, ret=0;
	int i = 0;
	while (1) {
		while (i < N && flowers[i].first <= cur_s + 1) {
			q.push(flowers[i].second);
			i++;
		}
		if (q.empty() || q.top() <= cur_s) return no();
		cur_s = q.top(); ret++;
		q.pop();
		if (cur_s >= e) break;
	}
	printf("%d\n", ret);
	return 0;
}
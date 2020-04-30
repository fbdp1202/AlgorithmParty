#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=5001;
const int SIZE=1<<13;
typedef pair<int, int> P;
int N, M, d;
int arr[SIZE*2], visited[MAX_N];
P data[MAX_N];
priority_queue<P> pq[MAX_N];

int sum(int nodeL, int nodeR, int nodeNum, int L, int R) {
	if (R < nodeL || nodeR < L) return MAX_N;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL+nodeR)/2;
	return min(sum(nodeL, mid, nodeNum*2, L, R), sum(mid+1, nodeR, nodeNum*2+1, L, R));
}

int sum(int nodeL, int nodeR) {
	return sum(nodeL, nodeR, 1, 0, SIZE-1);
}

void update(int i, int val) {
	i+=SIZE;
	arr[i]=val;
	while (i > 1) {
		i/=2;
		arr[i] = min(arr[i*2], arr[i*2+1]);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=1; i<=MAX_N; i++)
		update(i, i-1);

	for (int i=0; i<N; i++)
		scanf("%d", &data[i].first);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i].second);

	for (int i=0; i<N; i++)
		pq[data[i].second].push(P(data[i].first, i));

	scanf("%d", &d);
	for (int i=0; i<d; i++) {
		int k;
		scanf("%d", &k);
		visited[k]=true;
		for (int j=0; j<N; j++) {
			if (!pq[j].empty()) {
				update(pq[j].top().first, pq[j].top().first);
				while (!pq[j].empty() && visited[pq[j].top().second]) {
					pq[j].pop();
				}
				if (!pq[j].empty()) {
					printf("update(%d %d)\n",pq[j].top().first,MAX_N);
					update(pq[j].top().first, MAX_N);
				}
			}
		}
		printf("%d\n", sum(0, MAX_N-1));
		for (int i=0; i<6; i++) {
			printf("%d: %d\n", i, arr[SIZE+i]);
		}
		puts("");
	}
	return 0;
}
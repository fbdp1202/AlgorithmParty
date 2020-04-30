// baekjoon 8980 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct _TAG_BOX{
	int f, t, w;
	_TAG_BOX(): _TAG_BOX(-1, -1, 9){}
	_TAG_BOX(int f1, int t1, int w1) : f(f1), t(t1), w(w1){}
	bool operator <(const _TAG_BOX& O)const{
		return (f == O.f) ? (t == O.t) ? (w < O.w) : (t < O.t) : (f < O.f);
	}
}__BOX;

int houses[2001];
__BOX boxes[10001];

int main() {
	int N, C, M, W, from, to, weight;
	scanf("%d%d%d", &N, &C, &M);

	for (int i=0; i<M; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		boxes[i] = __BOX(from, to, weight);
	}

	sort(boxes, boxes+M);

	int cnt = 0;
	int curr = 0;

	while (cnt!=M) {
		curr = boxes[cnt].f;

		while(curr == boxes[cnt].f){
			houses[boxes[cnt].t] += boxes[cnt].w;
			cnt++;
		}

		int total_weight=0;
		for (int i=curr+1; i<=N; i++) {
			total_weight += houses[i];
			if (total_weight > C){
				houses[i] -= total_weight-C;
				i++;
				while(i<=N) {
					houses[i++]=0;
				}
			}
		}
	}
	int result=0;
	for (int i=0; i<=N; i++) {
		result+=houses[i];
	}
	printf("%d\n", result);

	return 0;
}
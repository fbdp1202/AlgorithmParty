// algo Assginment 3
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=10001;
const int MAX_L=100001;
const int SIZE=1<<17;

struct Point{
	int l, r, y;
	Point(){}
	Point(int l, int r, int y):l(l), r(r), y(y){}
};

bool cmp_y(const Point& a, const Point& b){
	return a.y > b.y;
}

int T, N, arr[SIZE*2+1];
Point pos[MAX_N];

void update(int nodeL, int nodeR, int nodeNum, int L, int R, int val) {
	if (R < nodeL || nodeR < L) return;
	if (val < arr[nodeNum]) return;
	if (nodeL == L && nodeR == R) arr[nodeNum]=val;
	if (L == R) return;

	int mid=(L+R)/2;
	update(nodeL, min(mid, nodeR), nodeNum*2, L, mid, val);
	update(max(nodeL,mid+1), nodeR, nodeNum*2+1, mid+1, R, val);
}

void update(int nodeL, int nodeR, int val) {
	update(nodeL, nodeR, 1, 0, SIZE-1, val);
}

int main() {
	scanf("%d", &T);

	while (T--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d %d %d", &pos[i].l, &pos[i].r, &pos[i].y);
		sort(pos, pos+N, cmp_y);
		for (int i=0; i<N; i++) update(pos[i].l+1, pos[i].r, pos[i].y);
		for (int i=0; i<30; i++) printf("%d: %d\n", i, arr[i+SIZE]);
		int start=0;
		int val=0;
		for (int i=1; i<MAX_L; i++) {
			if (arr[i+SIZE] != val) {
				if (val) printf("%d %d %d\n", start-1, i-1, val);
				start=i;
				val=arr[i+SIZE];
			}
		}
		if (val) printf("%d %d %d\n", start-1, MAX_L-1, val);
	}
	return 0;
}
// postech Assignment5. 2.cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=300001;
const int SIZE=1<<20;

struct Point{
	int x, y;
	Point():Point(0,0){};
	Point(int x, int y):x(x), y(y){}
	bool operator<(const Point &o) {
		if (y == o.y) return x < o.x;
		return y < o.y;
	}
};

int t, N, x, y;
int arr[SIZE*2];
Point fish[MAX_N];

void update(int i, int val) {
	i+=SIZE;
	arr[i]=val;
	while (i > 1) {
		i/=2;
		arr[i] = max(arr[i*2], arr[i*2+1]);
	}
}

int segMax(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (nodeR < L || nodeL > R) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL+nodeR)/2;
	return max(segMax(L, R, nodeNum*2, nodeL, mid), segMax(L, R, nodeNum*2+1, mid+1, nodeR));
}

int segMax(int L, int R) {
	return segMax(L, R, 1, 0, SIZE-1);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d%d", &fish[i].x, &fish[i].y);
		sort(fish, fish+N);
		for (int i=0; i<N; i++)
			update(fish[i].x, segMax(0, fish[i].x)+1);
		printf("%d\n",segMax(0,1e6));
	}
	return 0;
}
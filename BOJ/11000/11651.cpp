// baekjoon 11651 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX_N=100001;

int N;
P points[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d %d", &points[i].second, &points[i].first);
	sort(points, points+N);
	for (int i=0; i<N; i++) 
		printf("%d %d\n", points[i].second, points[i].first);
	return 0;
}
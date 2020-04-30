// baekjoon 2528 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=3001;

int N, L, t;
pair<int, int> stick[MAX_N];

inline int getFst(int a, int t) {
	if (L-stick[a].first == 0) return 0;
	return (stick[a].second + t/(L-stick[a].first))%2 ? (L-stick[a].first-t%(L-stick[a].first)) : t%(L-stick[a].first);
}

inline int getScd(int a, int t) {
	if (L-stick[a].first == 0) return L;
	return (stick[a].second + t/(L-stick[a].first))%2 ? (L-t%(L-stick[a].first)) : t%(L-stick[a].first)+stick[a].first;
}

inline int gap(int a, int b, int t) {
	return min(abs(getFst(a, t)-getScd(b, t)), abs(getFst(b, t)-getScd(a, t)));
}

bool isOverlap(int a, int b, int t) {
	if (getScd(a, t) < getFst(b, t)) return false;
	if (getScd(b, t) < getFst(a, t)) return false;
	return true;
}

int main() {
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++)
		scanf("%d%d", &stick[i].first, &stick[i].second);

	int i=0; // curFloor
	while (i < N - 1) {
		while (i < N-1 && isOverlap(i, i+1, t)) i++;
		if (i == N-1) break;
		t += (gap(i, i+1, t)+1)/2;
	}
	printf("%d\n", t);
	return 0;
}
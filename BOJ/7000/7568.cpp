// baekjoon 7568 yechan
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int ,int> P;

int N, x, y;
P v[50];

bool isBigger(P a, P b){
	if (a.first > b.first && a.second > b.second) return true;
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d %d", &x, &y);
		v[i].first = x, v[i].second = y;
	}

	for (int i=0; i<N; i++) {
		int result = 1;
		for (int j=0; j<N; j++) {
			if (i == j) continue;
			if (isBigger(v[j], v[i])) result++;
		}
		printf("%d ", result);
	}

	return 0;
}
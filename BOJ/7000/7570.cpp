// baekjoon 7570 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1000001;
typedef pair<int, int> P;

int N;
P person[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &person[i].first);
		person[i].second=i;
	}
	sort(person, person+N);

	int ret = 0;
	int length = 1;
	for (int i=1; i<N; i++) {
		if (person[i-1].second < person[i].second) length++;
		else {
			ret = max(ret, length);
			length=1;
		}
	}
	ret = max(ret, length);
	printf("%d\n", N-ret);

	return 0;
}
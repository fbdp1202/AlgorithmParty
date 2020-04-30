// baekjoon 2456 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, X;
pair<pair<int,int>,pair<int, int>> data[3];

int main() {
	scanf("%d", &N);
	for (int j=0; j<3; j++)
		data[j].second.second=j+1;

	for (int i=0; i<N; i++) {
		for (int j=0; j<3; j++) {
			scanf("%d", &X);
			data[j].first.first += X;
			if (X == 3) data[j].first.second++;
			if (X == 2) data[j].second.first++;
		}
	}
	sort(data, data+3);

	if (data[2].first.first == data[1].first.first &&
		data[2].first.second == data[1].first.second &&
		data[2].second.first == data[1].second.first) {
		printf("0 %d\n", data[2].first.first);
	} else {
		printf("%d %d\n", data[2].second.second, data[2].first.first);
	}
	return 0;
}
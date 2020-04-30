// baekjoon 15686 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX_N 50
#define INF 987654321
typedef pair<int, int> P;

int N, M, data, result=INF;
vector<P> house, chicken;
bool visited[13];

int distance(P a, P b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int totalDistance(){
	int total=0;
	for (int i=0; i<house.size(); i++) {
		int tmp = INF;

		for (int j=0; j<chicken.size(); j++)
			if (visited[j])
				tmp = min(tmp, distance(house[i], chicken[j]));

		total += tmp;
	}
	return total;
}

void ChoiceChicken(int num, int start) {
	if (num == M) {
		result = min(result, totalDistance());
		return;
	}

	for (int i=start; i<chicken.size(); i++) {
		if (!visited[i]) {
			visited[i]=true;
			ChoiceChicken(num+1, i+1);
			visited[i]=false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d", &data);
			if (data == 1)
				house.push_back(P(i, j));
			if (data == 2)
				chicken.push_back(P(i, j));
		}
	}
	ChoiceChicken(0, 0);
	printf("%d\n", result);

	return 0;
}
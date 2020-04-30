// baekjoon 9506 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
	while (1) {
		scanf("%d", &N);
		vector<int> v;
		if (N == -1) return 0;
		int sum = 0;
		for (int i=1; i<=N/2; i++) {
			if (N%i == 0) {
				sum += i;
				v.push_back(i);
			}
		}
		if (sum == N) {
			printf("%d = %d", N, v[0]);
			for (int i=1; i<v.size(); i++) {
				printf(" + %d", v[i]);
			}
			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", N);
		}
	}
	return 0;
}
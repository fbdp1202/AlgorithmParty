// baekjoon 3040 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int people[9];

int main()
{
	int sum = 0;
	for (int i=0; i<9; i++) {
		scanf("%d", &people[i]);
		sum += people[i];
	}
	sort(people, people+9);

	for (int i=0; i<8; i++) {
		for (int j=i+1; j<9; j++) {
			if (sum - people[i] - people[j] == 100) {
				for (int k=0; k<9; k++) {
					if (i == k || j == k) continue;
					printf("%d\n", people[k]);
				}
				return 0;
			}
		}
	}

	return 0;
}
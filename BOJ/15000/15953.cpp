// baekjoon 15953 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int array1[6] = {500, 300, 200, 50, 30, 10};
int rank1[6]  = {1, 2, 3, 4, 5, 6};

int array2[5] = {512, 256, 128, 64,32};
int rank2[5]  = {1, 2, 4, 8, 16};

int main() {
	int T, a, b, result, rank;

	scanf("%d", &T);
	while(T--) {
		result=0;
		scanf("%d%d", &a, &b);
		if (a) {
			rank=0;
			for (int i=0; i<6; i++) {
				rank += rank1[i];
				if (a <= rank) {
					result += array1[i];
					break;
				}
			}
		}
		if (b) {
			rank=0;
			for (int i=0; i<5; i++) {
				rank += rank2[i];
				if (b <= rank) {
					result += array2[i];
					break;
				}
			}
		}
		printf("%d\n", result*10000);
	}

	return 0;
}
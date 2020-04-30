// baekjoon 15947 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char data[14][50] = {"baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"};
int check[14] = {0, 0, 2, 1, 0, 0, 2, 1, 0, 0, 2, 1, 0, 0};

int main() {
	scanf("%d", &N);
	int k = (N-1)/14;
	if (!check[(N-1)%14]) printf("%s\n", data[(N-1)%14]);
	else {
		k += check[(N-1)%14];
		if (k >= 5) printf("tu+ru*%d\n", k);
		else {
			printf("tu");
			for (int i=0; i<k; i++) printf("ru");
			puts("");
		}
	}
	return 0;
}
// baekjoon 4892 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int n[5];

int main()
{
	int t = 0;
	while (1) {
		t++;
		scanf("%d", &n[0]);
		if (!n[0]) break;
		printf("%d. ", t);
		n[1] = n[0]*3;
		n[2] = (n[1]+1)/2;
		n[3] = 3*n[2];
		n[4] = n[3]/9;
		printf("%s %d\n", (n[1] & 1) ? "odd" : "even", n[4]);
	}

	return 0;
}
// baekjoon 2947 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A[5];

int main()
{
	for (int i=0; i<5; i++)
		scanf("%d", &A[i]);

	bool check = true;
	while (check) {
		check = false;
		for (int i=0; i<4; i++) {
			if (A[i] > A[i+1]) {
				check = true;
				swap(A[i], A[i+1]);
				for (int j=0; j<5; j++)
					printf("%d ", A[j]);
				puts("");
			}
		}
	}
	return 0;
}
// baekjoon 2872 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=300001;

int N;
int arr[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	int here = N;
	for (int i=N-1; i>=0; i--)
		if (arr[i] == here) here--;

	printf("%d\n", here);
	return 0;
}	
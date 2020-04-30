// baekjoon 1551 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=21;

int N, K;
int arr[MAX_N];
char trash;

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		if (i != N-1) scanf("%c", &trash);
	}

	for (int i=0; i<K; i++) {
		for (int j=N-1; j>=i+1; j--) {
			arr[j] -= arr[j-1];
		}
	}

	for (int i=K; i<N; i++) {
		printf("%d", arr[i]);
		if (i != N-1) printf(",");
	}
	puts("");

}
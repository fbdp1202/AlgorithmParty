// baekjoon 2847 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int data[101];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &data[i]);
	}

	int ret = 0;
	int minV = data[N-1];
	for (int i=N-2; i>=0; i--) {
		if (data[i] < minV) {
			minV = data[i];
		} else {
			minV--;
			ret += data[i] - minV;
		}
	}
	printf("%d\n", ret);
	return 0;
}
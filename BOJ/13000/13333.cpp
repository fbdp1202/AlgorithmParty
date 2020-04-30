// baekjoon 13333 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=10001;

int N;
int data[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	sort(data, data+N);

	int p=0;
	for (int i=0; i<N; i++) {
		if (N-i <= data[i]) {
			p = max(p,N-i);
		}
	}
	printf("%d\n", p);
	return 0;
}
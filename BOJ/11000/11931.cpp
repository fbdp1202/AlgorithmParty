// baekjoon 11931 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000001;

int N, x, data[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		data[i] = -x;
	}
	sort(data, data+N);
	for (int i=0; i<N; i++)
		printf("%d\n", -data[i]);
}
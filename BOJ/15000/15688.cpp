// baekjoon 15688 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1000001;

int N;
int data[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	sort(data, data+N);
	for (int i=0; i<N; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}
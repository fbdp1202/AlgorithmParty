// baekjoon 10807 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int N, v;
int data[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);

	scanf("%d", &v);

	int cnt=0;
	for (int i=0; i<N; i++)
		if (data[i] == v)
			cnt++;

	printf("%d\n", cnt);
	return 0;
}
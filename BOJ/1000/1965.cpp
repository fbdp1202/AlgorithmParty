// baekjoon 1965 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int n, boxes[MAX_N], dp[MAX_N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &boxes[i]);

	int max_len = 1;

	for(int i=0; i<n; i++)
	{
		int tmp = 1;
		for(int j=0; j<i; j++)
			if(boxes[j] < boxes[i]) tmp = max(tmp, dp[j]+1);
		dp[i] = tmp;
		max_len = max(tmp, max_len);
	}
	printf("%d", max_len);
	return 0;
}
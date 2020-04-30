// baekjoon 11053 yechan (가장 긴 증가하는 부분 수열)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	int *A = new int[N];
	int *PA_len = new int[N];
	int max_len = 1;
	for (int i = 0; i < N; ++i) cin >> A[i];
	if(N == 1){ cout << 1; return 0; }

	PA_len[0] = 1;
	fill(PA_len+1, PA_len+N,0);

	for (int i = 1; i < N; ++i)
	{
		int tmp = 1;
		for (int j = 0; j < i; ++j)
			if(A[j] < A[i]) tmp = max(tmp, PA_len[j]+1);
		PA_len[i] = tmp;
		max_len = max(tmp, max_len);
	}
	cout << max_len;
}
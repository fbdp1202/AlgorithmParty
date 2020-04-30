// baekjoon 9007 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int T;
int K, N;
int weight[4][MAX_N];


int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &K, &N);
		vector<int> A, B;

		for (int d=0; d<4; d++)
			for (int i=0; i<N; i++)
				scanf("%d", &weight[d][i]);

		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				A.push_back(weight[0][i] + weight[1][j]);
				B.push_back(weight[2][i] + weight[3][j]);
			}
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		B.erase(unique(B.begin(), B.end()), B.end());

		int curr = 1e9;
		int ret = 1e9;
		int diff = 0;
		int Asize = A.size();
		int Bsize = B.size();
		int sum = 0;
		for (int i=0; i<Asize; i++) {
			int start = lower_bound(B.begin(), B.end(), K-ret-A[i]) - B.begin();
			for (int j=start; j<Bsize; j++) {
				sum = A[i] + B[j];
				diff = abs(sum - K);
				if (diff > ret) break;
				else if (diff == ret) curr = min(curr, sum);
				else ret = diff, curr = sum;
			}
		}
		printf("%d\n", curr);
	}
	return 0;
}